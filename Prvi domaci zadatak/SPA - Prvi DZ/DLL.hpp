#pragma once

typedef struct dnode
{
    std::string expression;
    std::string fileName;
    struct dnode *prev;
    struct dnode *next;
    dnode(const std::string &expression, const std::string &fileName) : expression(expression), fileName(fileName), prev(nullptr), next(nullptr) {}
} dNode;

class DLL
{
private:
    dNode *head;
    dNode *tail;
public:
    DLL();
    ~DLL();
    void add(const std::string &expression, const std::string &fileName);
    void showFileNames() const;
    void printFileExpression(const std::string &fileName) const;
};