#include <iostream>
#include <string>
#include "DLL.hpp"

using namespace std;

DLL::DLL() : head(nullptr), tail(nullptr) {}

DLL::~DLL()
{
    dNode *temp = this->head;
    while(temp != nullptr)
    {
        this->head = temp->next;
        delete temp;
        temp = this->head;
    }
}

void DLL::add(const string &expression, const string &fileName)
{
    dNode *newNode = new dNode(expression, fileName);
    if (this->head == nullptr)
        this->head = this->tail = newNode;
    else
    {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

void DLL::showFileNames() const
{
    dNode *temp = this->head;
    cout << "Lista kreiranih fajlova:" << endl;
    while(temp != nullptr)
    {
        cout << temp->fileName << endl;
        temp = temp->next;
    }
}

void DLL::printFileExpression(const string &fileName) const
{
    dNode *temp = this->head;
    while (temp != nullptr && temp->fileName != fileName)
        temp = temp->next;
    if(temp == nullptr)
        cout << "Nije pronadjen fajl sa unesenim nazivom!" << endl;
    else
        cout << temp->expression << endl;
}