#include <iostream>
#include <exception>

bool isHacksaw(int *arr, int n, char old)
{
    if (n == 1)
    {
        return true;
    }
    int num = *arr, nextNum = *(++arr);
    if (num == nextNum)
    {
        return false;
    }
    char curr = num > nextNum ? '>' : '<';
    if (curr == old)
    {
        return false;
    }

    return isHacksaw(arr, n - 1, curr);
}

void hacksaw(int *arr, int n)
{
    if (n < 3)
    {
        throw std::invalid_argument("Invalid number of arguments.");
    }

    std::cout << (isHacksaw(arr, n, '>') || isHacksaw(arr, n, '<') ? "yes\n" : "no\n");
}

int main()
{
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    try
    {
        hacksaw(arr, n);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    delete[] arr;
}