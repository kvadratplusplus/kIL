// * killogic.cpp
// * if and else of kil

#include <lang\killogic.h>

int index;
int stopIndex;

bool rValIsFloat = false;
bool lValIsFloat = false;

bool result;

int ilval;
float flval;

int irval;
float frval;

std::string oper;

void kilGoto()
{
    int offset;
    char ch;
    file >> offset >> ch;
    file.seekg(offset, std::ios::cur);
}

void ifLogic()
{
    std::string word;
    file >> index >> word;

    if(word == "ivar")
    {
        int address;
        file >> address;
        ilval = intVars.at(address);
    }
    else if(word == "fvar")
    {
        int address;
        file >> address;
        flval = floatVars.at(address);
        lValIsFloat = true;
    }
    else if(word == "inum")
    {
        file >> ilval;
    }
    else if(word == "fnum")
    {
        file >> flval;
        lValIsFloat = true;
    }
    else
    {
        std::cout << "ERROR KVD5: Unknown variable type: " << word << std::endl;
        std::exit(1);
    }

    file >> oper >> word;

    if(word == "ivar")
    {
        int address;
        file >> address;
        irval = intVars.at(address);
    }
    else if(word == "fvar")
    {
        int address;
        file >> address;
        frval = floatVars.at(address);
        rValIsFloat = true;
    }
    else if(word == "inum")
    {
        file >> irval;
    }
    else if(word == "fnum")
    {
        file >> frval;
        rValIsFloat = true;
    }
    else
    {
        std::cout << "ERROR KVD5: Unknown variable type: " << word << std::endl;
        std::exit(1);
    }

    comparison();
}

void comparison()   //sorry
{
    if (lValIsFloat || rValIsFloat)
    {
        float lValue = lValIsFloat ? flval : ilval;
        float rValue = rValIsFloat ? frval : irval;
        
        if (oper == ">")      result = lValue > rValue;
        else if (oper == "<") result = lValue < rValue;
        else if (oper == "==") result = lValue == rValue;
        else if (oper == "!=") result = lValue != rValue;
    }
    else
    {
        int lValue = ilval;
        int rValue = irval;
        
        if (oper == ">")      result = lValue > rValue;
        else if (oper == "<") result = lValue < rValue;
        else if (oper == "==") result = lValue == rValue;
        else if (oper == "!=") result = lValue != rValue;
    }

    if (result) return;
    else skip();
}

void skip()
{
    char ch;
    while(file.get(ch))
    {
        std::string word;
        file >> word;
        if(word == "#")
        {
            file >> stopIndex;
            if(stopIndex != index)
            {
                continue;
            }
            else
            {
                return;
            }
        }
    }
}