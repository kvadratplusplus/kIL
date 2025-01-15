// * kilvars.h
// * variables of kIL
// ! WORK IN PROGRESS!!!
#ifndef KILVARS_H
#define KILVARS_H

#include <string>
#include <vector>
#include <iostream> // ! REMOVE AFTER TEST!!!
#include <main.h>

//int integersCount = 0;
//int floatsCount = 0;

void initInt();

class FloatVar {
private:
    std::string m_floatName;
    double m_floatValue;

public:
    FloatVar(const std::string &floatName, double floatValue)
        : m_floatName(floatName), m_floatValue(floatValue) {}

    std::string getFloatName() const { return m_floatName; }
    double getFloatValue() const { return m_floatValue; }

    void setFloatName(const std::string &newName) { m_floatName = newName; }
    void setFloatValue(double newValue) { m_floatValue = newValue; }
};

class IntegerVar {
private:
    std::string m_intName;
    int m_intValue;

public:
    IntegerVar(const std::string &intName, int intValue)
        : m_intName(intName), m_intValue(intValue) {}

    std::string getIntName() const { return m_intName; }
    int getIntValue() const { return m_intValue; }

    void setIntName(const std::string &newName) { m_intName = newName; }
    void setIntValue(int newValue) { m_intValue = newValue; }
};

extern std::vector<IntegerVar> integers;
extern std::vector<FloatVar> floats;

// extern std::vector<IntegerVar>* integers;
// extern std::vector<FloatVar>* floats;

#endif