#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static void handleStreamError()
{
    std::cout << std::endl;
    if (std::cin.eof())
        std::cout << "EOF detected. Exiting." << std::endl;
    else
        std::cout << "Input stream error. Exiting." << std::endl;
}

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        
        //input stream error or eof
        if (!std::getline(std::cin, cmd))
        {
            handleStreamError();
            break;
        }
        if (cmd == "ADD")
        {
            pb.addContact();
            if (std::cin.fail())
            {
                handleStreamError();
                break;
            }
        }
        else if (cmd == "SEARCH")
        {
            pb.searchContact();
            if (std::cin.fail())
            {
                handleStreamError();
                break;
            }
        }
        else if (cmd == "EXIT")
            break;
        else 
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}