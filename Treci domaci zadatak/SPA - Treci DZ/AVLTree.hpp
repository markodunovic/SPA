#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "AVLNode.hpp"

class AVLTree
{
private:
    AVLNode *root;
public:
    AVLTree() : root(nullptr) {}

    void insert(const std::string &key)
    {
        this->root = this->insertInternal(this->root, key);
    }
    std::vector<int> wordLengths()
    {
        std::vector<int> lengths;
        this->wordLengthsInternal(root, lengths);
        return lengths;
    }
    void printInOrder(std::ostream& os) const
    {
        printInOrderInternal(root, os);
    }
private:
    void printInOrderInternal(AVLNode* node, std::ostream& os) const
    {
        if (node != nullptr)
        {
            printInOrderInternal(node->getLeft(), os);
            os << node->getKey() << " ";
            printInOrderInternal(node->getRight(), os);
        }
    }
    AVLNode* insertInternal(AVLNode* node, const std::string &key)
    {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->getKey())
            node->setLeft(insertInternal(node->getLeft(), key));
        else if (key > node->getKey())
            node->setRight(insertInternal(node->getRight(), key));
        else
            return node;

        node->setHeight(1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight())));

        int balance = getBalance(node);

        // Rotacije za balansiranje stabla
        if (balance > 1 && key < node->getLeft()->getKey())
            return rightRotate(node);
        if (balance < -1 && key > node->getRight()->getKey())
            return leftRotate(node);
        if (balance > 1 && key > node->getLeft()->getKey())
        {
            node->setLeft(leftRotate(node->getLeft()));
            return rightRotate(node);
        }
        if (balance < -1 && key < node->getRight()->getKey())
        {
            node->setRight(rightRotate(node->getRight()));
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* rightRotate(AVLNode *y)
    {
        AVLNode *x = y->getLeft();
        AVLNode *T2 = x->getRight();

        x->setRight(y);
        y->setLeft(T2);

        y->setHeight(std::max(getHeight(y->getLeft()), getHeight(y->getRight())) + 1);
        x->setHeight(std::max(getHeight(x->getLeft()), getHeight(x->getRight())) + 1);

        return x;
    }

    AVLNode* leftRotate(AVLNode *x)
    {
        AVLNode *y = x->getRight();
        AVLNode *T2 = y->getLeft();

        y->setLeft(x);
        x->setRight(T2);

        x->setHeight(std::max(getHeight(x->getLeft()), getHeight(x->getRight())) + 1);
        y->setHeight(std::max(getHeight(y->getLeft()), getHeight(y->getRight())) + 1);

        return y;
    }

    int getHeight(AVLNode *N)
    {
        if (N == nullptr)
            return 0;
        return N->getHeight();
    }

    int getBalance(AVLNode *N)
    {
        if (N == nullptr)
            return 0;
        return getHeight(N->getLeft()) - getHeight(N->getRight());
    }
    void wordLengthsInternal(AVLNode* node, std::vector<int> &lengths)
    {
        if (node != nullptr) {
            this->wordLengthsInternal(node->getLeft(), lengths);
            lengths.push_back(node->getKey().length());
            this->wordLengthsInternal(node->getRight(), lengths);
        }
    }
};

std::ostream& operator<<(std::ostream &os, const AVLTree& tree)
{
    tree.printInOrder(os);
    return os;
}