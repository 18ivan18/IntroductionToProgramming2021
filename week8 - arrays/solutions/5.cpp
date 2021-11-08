#include <iostream>

const int MAX_ELEMENTS = 20;
int main()
{
    int n, k;
    std::cin >> n;
    int arr[MAX_ELEMENTS];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cin >> k;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
