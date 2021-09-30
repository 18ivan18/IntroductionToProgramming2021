#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    const char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char *hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char *thousands[] = {"", "M", "MM", "MMM"};

    std::cout << thousands[num / 1000] << hundreds[(num % 1000) / 100] << tens[(num % 100) / 10] << ones[num % 10];
}