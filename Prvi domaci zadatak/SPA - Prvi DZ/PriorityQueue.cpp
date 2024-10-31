#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.hpp"

using namespace std;

PriorityQueue::PriorityQueue() : front(nullptr), rear(nullptr) {}

PriorityQueue::~PriorityQueue()
{
    Node *temp = this->front;
    while(temp != nullptr)
    {
        this->front = temp->next;
        delete temp;
        temp = this->front;
    }
}

void PriorityQueue::add(const string &data)
{
    Node *newNode = new Node;
    newNode->expression = data;
    newNode->next = nullptr;
    if(this->isEmpty())
        this->front = this->rear = newNode;
    else if(data.length() >= this->front->expression.length())
    {
        newNode->next = this->front;
        this->front = newNode;
    }
    else
    {
        Node *current = this->front;
        while(current->next != nullptr && data.length() < current->next->expression.length())
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
        if(newNode->next == nullptr)
            this->rear = newNode;
    }
}

bool PriorityQueue::infixToPrefix()
{
    if (this->isEmpty())
    {
        cout << "Red prazan!" << endl;
        return false;
    }
    Node *temp = this->front;
    while(temp != nullptr)
    {
        temp->expression = convertToPrefix(temp->expression);
        temp = temp->next;
    }
    return true;
}

void PriorityQueue::convertToJSON(DLL &dlista)
{
    Node *temp = this->front;
    if(temp != nullptr)
    {
        int successfully = 1;
        int unsuccessfully = 0;
        while(temp != nullptr)
        {
            int index = 0;
            Tree *root = formExpression(temp->expression, index);
            if(root)
            {
                string jsonExp = toJSON(root);
                string fileName = "izraz_" + std::to_string(successfully) + "_.json";
                writeJsonToFile(fileName, jsonExp);
                
                dlista.add(jsonExp, fileName);

                temp = temp->next;
                successfully++;
            }
                else
                    unsuccessfully++;
        }
        successfully--;
        cout << "Broj uspjesnih konverzija: " << successfully << endl;
        cout << "Broj neuspjesnih konverzija: " << unsuccessfully << endl;
    }
}

void PriorityQueue::writeJsonToFile(const string &fileName, const string &jsonExp)
{
    ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        outputFile << jsonExp;
        outputFile.close();
    }
}

bool PriorityQueue::isEmpty() const
{
    return this->front == nullptr;
}