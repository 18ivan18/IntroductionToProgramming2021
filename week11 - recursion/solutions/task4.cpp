#include <iostream>

double sumRec(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return sumRec(n - 1) + 1.0 / n;
}

double sumRec(int n, int startVal)
{
    if (startVal > n)
    {
        return 1;
    }

    return sumRec(n, startVal + 1) + 1.0 / startVal;
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << sumRec(n) << std::endl;
}