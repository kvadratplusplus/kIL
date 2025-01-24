// * kilio.cpp
// * input and output of kIL
#include <lang\kilio.h>

void print()
{
    char ch;
    file.get(ch);
    while (file.get(ch))
    {
        if (ch == ';')
        {
            break;
        }
        std::cout << ch;
    }
}

void endLine()
{
    std::cout << std::endl;
}

void sleep()
{
    char ch;
    long long time;
    file >> time;
    file >> ch;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}