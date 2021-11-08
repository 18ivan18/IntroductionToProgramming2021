#include <iostream>

const int MAX_ELEMENTS = 20;
int main()
{
    int n, m, position;
    std::cin >> n;
    int arr[MAX_ELEMENTS]; //corner case if n = 20 shifts the last element

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cin >> m >> position;

    for (int i = n; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    n++;
    arr[position] = m;

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
