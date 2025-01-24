// * main.h
// * kIL interpreter
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>

#include <lang\kilio.h>
#include <lang\kilvars.h>
#include <lang\killogic.h>

#include <lang\kilmath.h>

extern std::ifstream file;
extern std::vector<int> intVars;
extern std::vector<float> floatVars;

#endif