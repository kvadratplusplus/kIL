// * main.cpp
// * kIL interpreter
#include <main.h>

std::ifstream file;

int main(int argc, char* argv[])
{
    std::string word;
    std::string fileName;
    
    if(argc == 1)
    {
        fileName = "main";
    }
    if (argc == 2)
    {
        fileName = argv[1];
    }
    
    file.open(fileName + ".kvd");
    if(!file.is_open())
    {
        std::cerr << "ERROR KVD1: File \"" << fileName <<  ".kvd\" is not exist" << std::endl;
        return 1;
    }

    while (file >> std::ws && !file.eof())
    {
        file >> word;
        if(word == "ivar")
        {
            var(false);
        }
        else if(word == "fvar")
        {
            var(true);
        }
        else if(word == "print")
        {
            print();
        }
        else if(word == "endl;")
        {
            endLine();
        }
        else if(word == "sum")
        {
            intCalc(1);
        }
        else if(word == "dif")
        {
            intCalc(2);
        }
        else if(word == "mul")
        {
            intCalc(3);
        }
        else if(word == "div")
        {
            intCalc(4);
        }
        else if(word == "fsum")
        {
            floatCalc(1);
        }
        else if(word == "fdif")
        {
            floatCalc(2);
        }
        else if(word == "fmul")
        {
            floatCalc(3);
        }
        else if(word == "fdiv")
        {
            floatCalc(4);
        }
        else if(word == "sleep")
        {
            sleep();
        }
        else if(word == "//")
        {
            char ch;
            while (file.get(ch))
            {
                if (ch == ';')
                {
                    break;
                }
            }
        }

        else
        {
            std::cout << "ERROR KVD2: Unknown command: " << word << std::endl;
            return 1;
        }
    }

    file.close();
    return 0;
}