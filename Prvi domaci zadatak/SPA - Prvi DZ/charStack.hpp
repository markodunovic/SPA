#pragma once

typedef struct cnode
{
    char character;
    struct cnode *next;
    cnode(char c) : character(c), next(nullptr) {}
} cNode;

class charStack
{
private:
    cNode *tos;
public:
    charStack();
    ~charStack();
    void push(char c);
    bool pop();
    char top() const;
    bool isEmpty() const;
};