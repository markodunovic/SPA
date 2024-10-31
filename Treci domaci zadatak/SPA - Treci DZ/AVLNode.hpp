#pragma once
#include <string>

class AVLNode
{
private:
    std::string key;
    AVLNode *left, *right;
    int height;
public:
    AVLNode(std::string k) : key(k), left(nullptr), right(nullptr), height(1) {}

    std::string getKey() const
    {
        return this->key;
    }
    AVLNode* getLeft() const
    {
        return this->left;
    }
    void setLeft(AVLNode* node)
    {
        this->left = node;
    }
    AVLNode* getRight() const
    {
        return this->right;
    }
    void setRight(AVLNode* node)
    {
        this->right = node;
    }
    int getHeight() const
    {
        return this->height;
    }
    void setHeight(int h)
    {
        this->height = h;
    }
};