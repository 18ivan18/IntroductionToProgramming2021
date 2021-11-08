#include <iostream>

const int MAX_SIZE = 20;

int main()
{
    int arr[MAX_SIZE], n;
    do
    {
        std::cin >> n;
    } while (n < 0 || n >= 20);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}