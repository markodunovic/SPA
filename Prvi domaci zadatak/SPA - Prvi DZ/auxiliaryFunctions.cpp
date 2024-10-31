#include <iostream>
#include <string>
#include <algorithm>
#include "auxiliaryFunctions.hpp"

using namespace std;

// Elementarne funkcije
bool isOperand(const char c)
{
    return isalpha(c) || isdigit(c);
}

bool isOperator(const char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPriority(const char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

bool isValid(const string &other)
{
    int expOperand = 0;
    int expOperator = 0;
    for(int i = 0; i < other.length(); i++)
    {
        if (isOperand(other[i]))
            expOperand++;
        else if (isOperator(other[i]))
            expOperator++;
    }
    return (expOperand - expOperator) == 1;
}

// Funkcije za računanje prefiksnog izraza:
int performOperation(char op, int operand1, int operand2) {
    switch (op)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else
            {
                cout << "Greska! Dijeljenje sa nulom!" << endl;
                exit(EXIT_FAILURE);
            }
        default:
            cout << "Greska! Nedozvoljen operator!" << endl;
            exit(EXIT_FAILURE);
    }
}

int calculatePrefixExpression(const std::string& expression)
{
    charStack charStack;

    // Prolazak kroz izraz s desna na lijevo
    for (int i = expression.size() - 1; i >= 0; --i)
    {
        char currentChar = expression[i];

        if (isdigit(currentChar))
        {
            // Ako je cifra stavljamo na stek
            charStack.push(currentChar);
        }
        else if (isOperator(currentChar))
        {
            // Ako je operator, izvodimo operaciju na operandima sa steka
            if (charStack.isEmpty())
            {
                cout << "Greska: Neispravan izraz!" << endl;
                exit(EXIT_FAILURE);
            }
            char operand1 = charStack.top() - '0';
            charStack.pop();

            if (charStack.isEmpty())
            {
                cout << "Greska: Neispravan izraz!" << endl;
                exit(EXIT_FAILURE);
            }

            char operand2 = charStack.top() - '0';
            charStack.pop();

            int result = performOperation(currentChar, operand1, operand2);

            // Stavljamo rezultat na stek
            charStack.push(result + '0');
        }
        else if (currentChar == '(' || currentChar == ')')
        {
            // Preskoči zagrade u prefiksnoj notaciji
            continue;
        }
        else
        {
            // Ako je nepoznat karakter, javljamo grešku
            cout << "Greska: Neispravan karakter u izrazu!" << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Na kraju izraza, rezultat mora biti na vrhu steka
    if (charStack.isEmpty())
    {
        cout << "Greska: Neispravan izraz!" << endl;
        exit(EXIT_FAILURE);
    }

    return charStack.top() - '0';
}