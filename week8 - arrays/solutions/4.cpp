#include <iostream>

const int MAX_ELEMENTS = 20;

int main()
{
    int n;
    std::cin >> n;
    int arr[MAX_ELEMENTS];
    bool upper = true, lower = true;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            lower = false;
        }
        if (arr[i] > arr[i + 1])
        {
            upper = false;
        }
    }

    if (upper == true && lower == true)
    {
        std::cout << "The sequence is with equal elements\n";
    }
    else if (upper == true)
    {
        std::cout << "The sequence is increasing\n";
    }
    else if (lower == true)
    {
        std::cout << "The sequence is decreasing\n";
    }
    else
    {
        std::cout << "The sequence is neither increasing nor decreasing\n";
    }
}
