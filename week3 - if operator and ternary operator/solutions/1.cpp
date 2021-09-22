#include <iostream>

int main()
{
    int first, second, third;
    std::cin >> first >> second >> third;
    if (first >= second && first >= third)
    {
        std::cout << first << std::endl;
    }
    else if (second >= first && second >= third)
    {
        std::cout << second << std::endl;
    }
    else if (third >= first && third >= second)
    {
        std::cout << third << std::endl;
    }
}