// * killogic.cpp
// * if and else of kil
#ifndef KILLOGIC_H
#define KILLOGIC_H

#include <main.h>

extern int index;
extern int stopIndex;
extern bool rValIsFloat;
extern bool lValIsFloat;
extern int ilval;
extern float flval;
extern int irval;
extern float frval;
extern std::string oper;
extern bool result;

void ifLogic();
void skip();
void comparison();
void kilGoto();

#endif