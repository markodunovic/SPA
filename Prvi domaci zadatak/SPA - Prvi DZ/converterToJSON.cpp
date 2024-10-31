#include <iostream>
#include <string>
#include "converterToJSON.hpp"

using namespace std;

Tree *formExpression(const string &expression, int &index)
{
    if (index >= expression.size())
        return nullptr;

    char currentChar = expression[index];
    Tree *newNode = new Tree(currentChar);

    index++;

    if (isOperator(currentChar))
    {
        newNode->left = formExpression(expression, index);
        newNode->right = formExpression(expression, index);
    }

    return newNode;
}

string toJSON(Tree *root, int indentation)
{
    if (root == nullptr)
        return "";

    if (root->left == nullptr && root->right == nullptr)
        return "\"" + string(1, root->data) + "\"";

    string result = "{\n";
    result += addIndentation(indentation + 1) + "\"operation\": \"" + string(1, root->data) + "\",\n";
    result += addIndentation(indentation + 1) + "\"left\": " + toJSON(root->left, indentation + 1) + ",\n";
    result += addIndentation(indentation + 1) + "\"right\": " + toJSON(root->right, indentation + 1) + "\n";
    result += addIndentation(indentation) + "}";

    return result;
}

string addIndentation(int count) {
    return string(count * 4, ' '); // 4 mjesta po nivou
}
