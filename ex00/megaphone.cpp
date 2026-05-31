#include <iostream>
#include <cctype> //std::toupper

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; ++i)
        {
            for (int j = 0; av[i][j]; ++j)
            {
                unsigned char c = static_cast<unsigned char>(av[i][j]);
                std::cout << static_cast<char>(std::toupper(c));
            }
            if (i != ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
