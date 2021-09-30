#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int gcd = 1;
    for (int i = 1; i <= n && i <= m; i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            gcd = i;
        }
    }
    std::cout << "The Greatest Common Divisor is: " << gcd << std::endl;
}