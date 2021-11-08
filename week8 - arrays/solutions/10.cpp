#include <iostream>

int main()
{
    int arr[] = {2, 7, 11, 15}, k = 9, size = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                std::cout << i << " " << j << std::endl;
                break;
            }
        }
    }
}