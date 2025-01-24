// * kilvars.cpp
// * variables of kIL
#include <lang\kilvars.h>

std::vector<int> intVars;
std::vector<float> floatVars;

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
    else if(func == "++")
    {
        addOne(isFloat);
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

void addOne(bool isFloatArr)
{
    int address;
    char ch;
    file >> address >> ch;
    if(isFloatArr) floatVars[address]++;
    else intVars[address]++;
}

void inputVar(bool isFloatArr)
{
    int address;
    char ch;

    while(file.get(ch))
    {
        if(ch == ';') break;
        file >> address;
        if(isFloatArr)
        {
            float fnum;
            std::cin >> fnum;

            if(address < floatVars.size() && address >= 0)
            {
                floatVars[address] = fnum;
            }
            else if(address > floatVars.size())
            {
                floatVars.resize(address + 1);
                floatVars[address] = fnum;
            }
            else
            {
                floatVars.push_back(fnum);
            }
        }
        else
        {
            int inum;
            std::cin >> inum;
            if(address < intVars.size() && address >= 0)
            {
                intVars[address] = inum;
            }
            else if(address > intVars.size())
            {
                intVars.resize(address + 1);
                intVars[address] = inum;
            }
            else
            {
                intVars.push_back(inum);
            }
        }
    }
}

void setVar(bool isFloatArr)
{
    int address;
    float fnum;
    int inum;
    char ch;
    while(file.get(ch))
    {
        if(ch == ';')
        {
            break;
        }
        file >> address;
        if(isFloatArr)
        {
            file >> fnum;
        }
        else
        {
            file >> inum;
        }
    }
    if(isFloatArr)
    {
        if(address < floatVars.size() && address >= 0)
        {
            floatVars[address] = fnum;
        }
        else if(address >= floatVars.size())
        {
            floatVars.resize(address + 1);
            floatVars[address] = fnum;
        }
    }
    else
    {
        if(address < intVars.size() && address >= 0)
        {
            intVars[address] = inum;
        }
        else if(address >= intVars.size())
        {
            intVars.resize(address + 1);
            intVars[address] = inum;
        }
    }
}

void printVar(bool isFloatArr)
{
    int address;
    char ch;
    file >> address >> ch;
    if(isFloatArr)
    {
        std::cout << floatVars.at(address);
    }
    else
    {
        std::cout << intVars.at(address);
    }
}

void varCalc(int mode, bool isFloatArr)
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
                std::cerr << "ERROR KVD3: Dividing by 0" << std::endl;
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
                std::cerr << "ERROR KVD3: Dividing by 0" << std::endl;
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
                std::cerr << "ERROR KVD3: Dividing by 0" << std::endl;
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
                std::cerr << "ERROR KVD3: Dividing by 0" << std::endl;
                std::exit(1);
            }
        }

        else
        {
            std::cerr << "ERROR KVD5: Unknown variable type: " << type << std::endl;
            std::exit(1);
        }
    }
    if(isFloatArr) floatVars[changeVariableAddress] = total;
    else intVars[changeVariableAddress] = total;
}

void showVariables()
{
    std::cout << "Initialized float vars:" << std::endl;
    for(int i = 0; i < floatVars.size(); i++)
    {
        std::cout << i << " " << floatVars.at(i) << std::endl;
    }

    std::cout << "Initialized int vars:" << std::endl;
    for(int i = 0; i < intVars.size(); i++)
    {
        std::cout << i << " " << intVars.at(i) << std::endl;
    }
}