#include <iostream>

void removeElement(int *arr, int n, int k)
{
    int *newarr = new int[n - 1];
    for (int i = 0; i < k; i++)
    {
        newarr[i] = arr[i];
    }
    for (int i = k; i < n - 1; i++)
    {
        newarr[i] = arr[i + 1];
    }
    delete[] arr;
    arr = new int[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = newarr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << arr[i];
    }
}

void removeColumn(int **matrix, int n, int m, int k)
{
    for (int i = 0; i < n; i++)
    {
        removeElement(matrix[i], m, k);
    }
}

void print(int **matrix, int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;

    int **dynamicMatrix = new int *[n];
    for (size_t i = 0; i < n; i++)
    {
        dynamicMatrix[i] = new int[n];
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> dynamicMatrix[i][j];
        }
    }

    removeElement(dynamicMatrix[1], n, 3);
    for (int i = 0; i < 4; i++)
    {
        std::cout << dynamicMatrix[1][i];
    }
    removeColumn(dynamicMatrix, n, n, 3);
    print(dynamicMatrix, n, n - 1);
}