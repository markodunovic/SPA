#pragma once
#include "node.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "auxiliaryFunctions.hpp"

// SinglyLinkedList
class SLL
{
private:
    Node *head;
public:
    SLL();
    ~SLL();
    void append(const std::string &expression); // Dodaje na pocetak
    void addToQueues(PriorityQueue &prQueue, Queue &usualQueue);
private:
    bool isEmpty() const;
};