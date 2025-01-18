// * kilmath.cpp
// * mathematical operations of kIL
#include <lang\kilmath.h>

// 1 = +
// 2 = -
// 3 = *
// 4 = /
void intCalc(int mode)  // * calculate integers
{
    char ch;
    int total = 0;
    int num = 0;

    file >> total;
    while (file.get(ch))
    {
        if (ch == ';')
        {
            break;
        }       
        file >> num;
        if(mode == 1) total += num;
        if(mode == 2) total -= num;
        if(mode == 3) total *= num;
        if(mode == 4 && num != 0)
        {
            total /= num;
        }
        else if(mode == 4 && num == 0)
        {
            std::cerr << "ERROR KVD3: dividing by 0" << std::endl;
            std::exit(1);
        }
    }
    std::cout << total;
}

// 1 = +
// 2 = -
// 3 = *
// 4 = /
void floatCalc(int mode)    // * calculate floats
{
    char ch;
    float total = 0;
    float num = 0;

    file >> total;
    while (file.get(ch))
    {
        if (ch == ';')
        {
            break;
        }       
        file >> num;
        if(mode == 1) total += num;
        if(mode == 2) total -= num;
        if(mode == 3) total *= num;
        if(mode == 4 && num != 0)
        {
            total /= num;
        }
        else if(mode == 4 && num == 0)
        {
            std::cerr << "ERROR KVD3: dividing by 0" << std::endl;
            std::exit(1);
        }
    }
    std::cout << total;
}

void sleep()
{
    char ch;
    long long time;
    file >> time;
    file >> ch;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}