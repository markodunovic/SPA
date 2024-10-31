#pragma once
#include "node.hpp"
#include "DLL.hpp"
#include "converterToPrefix.hpp"
#include "converterToJSON.hpp"

class PriorityQueue
{
private:
    Node *front;
    Node *rear;
public:
    PriorityQueue();
    ~PriorityQueue();
    void add(const std::string &data);
    bool infixToPrefix();
    void convertToJSON(DLL &dlista);
    void writeJsonToFile(const std::string &fileName, const std::string &jsonExp);
private:
    bool isEmpty() const;
};