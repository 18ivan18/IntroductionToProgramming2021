#include <iostream>
#include <cmath>

const int MAX_ELEMENTS = 20;

int main()
{
    int n;
    std::cin >> n;
    int arr[MAX_ELEMENTS];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    bool sym = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            sym = false;
            break;
        }
    }

    std::cout << std::boolalpha << sym;
}
