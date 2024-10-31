#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue()
{
    Node *temp = this->front;
    while(temp != nullptr)
    {
        this->front = temp->next;
        delete temp;
        temp = this->front;
    }
}

void Queue::enqueue(const string &data)
{
    Node *newNode = new Node;
    newNode->expression = data;
    newNode->next = nullptr;
    if(this->isEmpty())
        this->front = this->rear = newNode;
    else
    {
        this->rear->next = newNode;
        this->rear = newNode;
    }
}

bool Queue::isEmpty() const
{
    return this->front == nullptr;
}