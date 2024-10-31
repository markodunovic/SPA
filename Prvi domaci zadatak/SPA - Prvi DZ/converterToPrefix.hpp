#pragma once
#include "auxiliaryFunctions.hpp"
#include "charStack.hpp"

std::string convertToPrefix(std::string &infix);

std::string nearlyInfixToPostfix(std::string inverseInfix);