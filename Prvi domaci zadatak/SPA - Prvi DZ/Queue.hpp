#pragma once
#include "node.hpp"

class Queue
{
private:
    Node *front;
    Node *rear;
public:
    Queue();
    ~Queue();
    void enqueue(const std::string &data);
private:
    bool isEmpty() const;
};