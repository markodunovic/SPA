#include <iostream>
#include <algorithm>
#include "converterToPrefix.hpp"

using namespace std;

string convertToPrefix(string &infix)
{
    int length = infix.size();
    reverse(infix.begin(), infix.end());

    for(int i = 0; i < length; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string prefix = nearlyInfixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

string nearlyInfixToPostfix(std::string inverseInfix)
{
    inverseInfix = '(' + inverseInfix + ')';
    int infixLength = inverseInfix.size();
    charStack cStack;
    string result;

    for(int i = 0; i < inverseInfix.length(); i++)
    {
        char c = inverseInfix[i];

        // Operand? Dodaj u rezultujući string
        if (isalpha(c) || isdigit(c))
            result += c;

        // '(' ? Dodaj na stek 
        else if (c == '(')
            cStack.push(c);

        // ')' ? Skini sa steka i dodaj u rezultujući string dok god ne naiđeš na '('
        else if (c == ')')
        {
            while(cStack.top() != '(')
            {
                result += cStack.top();
                cStack.pop();
            }
            // Obriši '(' iz steka
            cStack.pop();
        }
        // Operator
        else
        {
            while(!cStack.isEmpty() && getPriority(inverseInfix[i]) < getPriority(cStack.top())) // Razlika: "<" umjesto "<="
            {
                result += cStack.top();
                cStack.pop();
            }
            // Push trenutni operator na Stack
            cStack.push(c);
        }
    }
    // Skini sve preostale elemente sa steka
    while(!cStack.isEmpty())
    {
        result += cStack.top();
        cStack.pop();
    }
    return result;
}