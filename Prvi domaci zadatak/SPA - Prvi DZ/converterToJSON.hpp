#pragma once
#include "auxiliaryFunctions.hpp"

typedef struct treeNode {
    char data;
    treeNode* left;
    treeNode* right;
    treeNode(char val) : data(val), left(nullptr), right(nullptr) {}
} Tree;

Tree* formExpression(const std::string &expression, int &index);

std::string toJSON(Tree *root, int indentation = 0);

std::string addIndentation(int count);
