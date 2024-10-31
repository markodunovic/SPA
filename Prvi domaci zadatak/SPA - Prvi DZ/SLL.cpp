#include <iostream>
#include <string>
#include "SLL.hpp"

using namespace std;

SLL::SLL() : head(nullptr) {}

SLL::~SLL()
{
    Node *temp = this->head;
    while(temp != nullptr)
    {
        this->head = temp->next;
        delete temp;
        temp = this->head;
    }
}

// Dodaje na pocetak
void SLL::append(const string &expression)
{
    Node *newNode = new Node;
    newNode->expression = expression;
    newNode->next = this->head;
    this->head = newNode;
}

void SLL::addToQueues(PriorityQueue &prQueue, Queue &usualQueue)
{
    Node *temp = this->head;
    while(temp != nullptr)
    {
        if(isValid(temp->expression))
            prQueue.add(temp->expression);
        else
            usualQueue.enqueue(temp->expression);
        this->head = temp->next;
        delete temp;
        temp = this->head;
    }
}

bool SLL::isEmpty() const
{
    return this->head == nullptr;
}