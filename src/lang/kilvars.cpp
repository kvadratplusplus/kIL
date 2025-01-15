// * kilvars.cpp
// * variables of kIL
// ! WORK IN PROGRESS!!!
#include <lang\kilvars.h>

std::vector<IntegerVar> integers;
std::vector<FloatVar> floats;

// class IntegerVar
// {
// public:
//     IntegerVar(std::string intName, int intValue);
//     int intValue;
//     std::string intName;
// };

// class FloatVar
// {
// public:
//     FloatVar(std::string floatName, double floatValue);
//     double floatValue;
//     std::string floatName;
// };

// class FloatVar {
// private:
//     std::string m_floatName;
//     double m_floatValue;

// public:
//     FloatVar(const std::string &floatName, double floatValue)
//         : m_floatName(floatName), m_floatValue(floatValue) {}

//     std::string getFloatName() const { return m_floatName; }
//     double getFloatValue() const { return m_floatValue; }

//     void setFloatName(const std::string &newName) { m_floatName = newName; }
//     void setFloatValue(double newValue) { m_floatValue = newValue; }
// };

// class IntegerVar {
// private:
//     std::string m_intName;
//     int m_intValue;

// public:
//     IntegerVar(const std::string &intName, int intValue)
//         : m_intName(intName), m_intValue(intValue) {}

//     std::string getIntName() const { return m_intName; }
//     int getIntValue() const { return m_intValue; }

//     void setIntName(const std::string &newName) { m_intName = newName; }
//     void setIntValue(int newValue) { m_intValue = newValue; }
// };

void initInt()
{
    std::string name;
    int val;
    
    file >> name >> val;
    IntegerVar newInteger(name, val);
    integers.push_back(newInteger);
    
    //std::cout << "new int: " << integers[0].getIntName() << integers[0].getIntValue();  // ! REMOVE AFTER TEST!!!
}