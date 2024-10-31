#pragma once
#include <iostream>
#include <string>

typedef struct node
{
    std::string expression;
    struct node *next;
} Node;