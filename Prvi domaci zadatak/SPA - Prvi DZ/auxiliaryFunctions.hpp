#pragma once
#include "charStack.hpp"

bool isOperand(const char c);

bool isOperator(const char c);

int getPriority(const char c);

bool isValid(const std::string &other);

int performOperation(char op, int operand1, int operand2);

int calculatePrefixExpression(const std::string &expression);