#include <string>
#include <limits.h>
#include <iostream>
#include <float.h>

int int_input(std::string prompt, int lower = INT_MIN, int upper = INT_MAX);

double double_input(std::string prompt, double lower = DBL_MIN, double upper = DBL_MAX);

std::string string_input(std::string, std::string*, int);