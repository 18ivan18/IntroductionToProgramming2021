#include <iostream>

int minDigit(int num)
{
    if (num == 0)
    {
        return INT32_MAX;
    }
    return std::min(minDigit(num / 10), num % 10);
}

int smallestDigitUtil(int n, int smallestDigit)
{
    if (n == 0)
    {
        return smallestDigit;
    }
    if (n % 10 < smallestDigit)
    {
        return smallestDigitUtil(n / 10, n % 10);
    }
    return smallestDigitUtil(n / 10, smallestDigit);
}

int smallestDigit(int n)
{
    return smallestDigitUtil(n, n % 10);
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << smallestDigit(n) << std::endl;
    std::cout << minDigit(n) << std::endl;
}