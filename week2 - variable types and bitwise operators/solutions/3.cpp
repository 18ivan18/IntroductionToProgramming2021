#include <iostream>

int main()
{
    double first_number;
    double second_number;

    std::cin >> first_number >> second_number;

    //a) с помощна променлива; в случая променливата с;
    double c = first_number;
    first_number = second_number;
    second_number = c;
    std::cout << "a = " << first_number << ", b = " << second_number << std::endl;

    //б) с аритметични операции
    first_number = first_number + second_number;
    second_number = first_number - second_number;
    first_number = first_number - second_number;
    std::cout << "a = " << first_number << ", b = " << second_number << std::endl;
}