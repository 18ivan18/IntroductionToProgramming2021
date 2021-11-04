#include <iostream>
#include <climits>

void threeLargest(int arr[], int size)
{
    int first, second, third;

    if (size < 3)
    {
        std::cout << "Invalid Input";
    }

    third = first = second = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second)
        {
            third = second;
            second = arr[i];
        }

        else if (arr[i] > third)
            third = arr[i];
    }

    std::cout << "\nThree largest elements are: " << first << ", " << second << ", " << third;
}

int getLargest(int *arr, int size)
{
    int largest = INT_MIN;
    for (size_t i = 0; i < size; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }
    return largest;
}