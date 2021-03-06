#include <iostream>
#include <climits>

int maxRow(int **matrix, int n)
{
    int max = INT_MAX, sum, maxRow;
    for (size_t i = 0; i < n; i++)
    {
        sum = 0;
        for (size_t j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }
        if (sum > max)
        {
            maxRow = i;
            max = sum;
        }
    }
}

int maxCol(int **matrix, int n)
{
    int max = INT_MAX, sum, maxRow;
    for (size_t i = 0; i < n; i++)
    {
        sum = 0;
        for (size_t j = 0; j < n; j++)
        {
            sum += matrix[j][i];
        }
        if (sum > max)
        {
            maxRow = i;
            max = sum;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << maxCol(matrix, n) << std::endl;
    std::cout << maxRow(matrix, n) << std::endl;
}