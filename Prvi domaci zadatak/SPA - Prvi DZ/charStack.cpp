#include <iostream>
#include "charStack.hpp"

using namespace std;

charStack::charStack() : tos(nullptr) {}

charStack::~charStack()
{
    while(!this->isEmpty())
        this->pop();
}

void charStack::push(char c)
{
    cNode *newNode = new cNode(c);
    newNode->next = this->tos;
    this->tos = newNode;
}

bool charStack::pop()
{
    if(this->isEmpty())
    {
        cout << "Stack is empty!\n";
        return false;
    }
    cNode *temp = this->tos;
    this->tos = temp->next;
    delete temp;
    return true;
}

char charStack::top() const
{
    return this->tos->character;
}

bool charStack::isEmpty() const
{
    return this->tos == nullptr;
}