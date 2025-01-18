// * kilvars.cpp
// * variables of kIL
#include <lang\kilvars.h>

int intVars[10];
float floatVars[10];

void var(bool isFloat)
{
    std::string func;
    file >> func;
    if(func == "set")
    {
        setVar(isFloat);
    }
    else if(func == "print")
    {
        printVar(isFloat);
    }
    else if(func == "input")
    {
        inputVar(isFloat);
    }
    else if(func == "sum")
    {
        varCalc(1, isFloat);
    }
    else if(func == "dif")
    {
        varCalc(2, isFloat);
    }
    else if(func == "mul")
    {
        varCalc(3, isFloat);
    }
    else if(func == "div")
    {
        varCalc(4, isFloat);
    }

    else
    {
        std::cerr << "ERROR KVD4: Unknown operation on variables: " << func << std::endl;
        std::exit(1);
    }
}

void inputVar(bool isFloatArr)
{
    int address;
    int inum;
    float fnum;
    char ch;

    while(file.get(ch))
    {
        if(ch == ';') break;
        file >> address;
        if(isFloatArr)
        {
            std::cin >> fnum;
            floatVars[address] = fnum;
        }
        else
        {
            std::cin >> inum;
            intVars[address] = inum;
        }
    }
}

void setVar(bool isFloatArr)
{
    int address;
    float fnumber;
    int inumber;
    char ch;
    while(file.get(ch))
    {
        if(ch == ';') break;
        file >> address;
        if(isFloatArr)
            file >> fnumber;
        else
            file >> inumber;
    }
    if(isFloatArr)
        floatVars[address] = fnumber;
    else
        intVars[address] = inumber;
}

void printVar(bool isFloatArr)
{
    int address;
    char ch;
    while(file.get(ch))
    {
        if(ch == ';') break;
        file >> address;
    }
    if(isFloatArr)
        std::cout << floatVars[address];
    else
        std::cout << intVars[address];
}

void varCalc(int mode, bool isFloat)
{
    int changeVariableAddress;
    std::string type;
    int address;

    int inum;
    float fnum;
    float total;

    char ch;

    file >> changeVariableAddress >> type;
    if(type == "fvar")
    {
        file >> address;
        total = floatVars[address];
    }
    else if(type == "ivar")
    {
        file >> address;
        total = intVars[address];
    }
    else if(type == "inum")
    {
        file >> inum;
        total = inum;
    }
    else if(type == "fnum")
    {
        file >> fnum;
        total = fnum;
    }
    else
    {
        std::cerr << "ERROR KVD5: Unknown variable type: " << type << std::endl;
        std::exit(1);
    }

    while(file.get(ch))
    {
        if(ch == ';') break;

        file >> type;

        if(type == "ivar")
        {
            file >> address;
            if(mode == 1) total += intVars[address];
            if(mode == 2) total -= intVars[address];
            if(mode == 3) total *= intVars[address];
            if(mode == 4 && intVars[address] != 0)
            {
                total /= intVars[address];
            }
            else if(mode == 4 && intVars[address] == 0)
            {
                std::cerr << "ERROR KVD3: dividing by 0" << std::endl;
                std::exit(1);
            }
        }
        else if(type == "fvar")
        {
            file >> address;
            if(mode == 1) total += floatVars[address];
            if(mode == 2) total -= floatVars[address];
            if(mode == 3) total *= floatVars[address];
            if(mode == 4 && floatVars[address] != 0)
            {
                total /= floatVars[address];
            }
            else if(mode == 4 && floatVars[address] == 0)
            {
                std::cerr << "ERROR KVD3: dividing by 0" << std::endl;
                std::exit(1);
            }
        }
        else if(type == "inum")
        {
            file >> inum;
            if(mode == 1) total += inum;
            if(mode == 2) total -= inum;
            if(mode == 3) total *= inum;
            if(mode == 4 && inum != 0)
            {
                total /= inum;
            }
            else if(mode == 4 && inum == 0)
            {
                std::cerr << "ERROR KVD3: dividing by 0" << std::endl;
                std::exit(1);
            }
        }
        else if(type == "fnum")
        {
            file >> fnum;
            if(mode == 1) total += fnum;
            if(mode == 2) total -= fnum;
            if(mode == 3) total *= fnum;
            if(mode == 4 && fnum != 0)
            {
                total /= fnum;
            }
            else if(mode == 4 && fnum == 0)
            {
                std::cerr << "ERROR KVD3: dividing by 0" << std::endl;
                std::exit(1);
            }
        }

        else
        {
            std::cerr << "ERROR KVD5: Unknown variable type: " << type << std::endl;
            std::exit(1);
        }
    }
    if(isFloat) floatVars[changeVariableAddress] = total;
    else intVars[changeVariableAddress] = total;
}