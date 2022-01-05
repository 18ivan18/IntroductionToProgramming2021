#include <iostream>

double func(int m, int n)
{
    if (m == 0)
    {
        return n;
    }

    return 1 + 1 / func(m - 1, n);
}

int main()
{
    int n, x;

    std::cin >> n >> x;

    std::cout << func(x, n) << std::endl;
}