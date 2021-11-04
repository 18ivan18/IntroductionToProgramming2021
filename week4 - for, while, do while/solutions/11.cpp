#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    int rev = 0;
    do
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    } while (n != 0);
    std::cout << rev << std::endl;
}