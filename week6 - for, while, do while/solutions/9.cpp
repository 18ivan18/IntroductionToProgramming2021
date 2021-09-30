#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    int k = 2;
    while (n != 1)
    {
        if (n % k == 0)
        {
            std::cout << k << " ";
            n = n / k;
            continue;
        }
        k++;
    }
    std::cout << std::endl;
}