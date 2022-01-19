#include <iostream>
#include <cstring>

bool outOfBounds(int x, int y, int n, int m)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool findWord(char **matrix, int n, int m, const char *word, bool **visited, int currentX, int currentY, char *currentPath, int currentPathIdx)
{
    if (outOfBounds(currentX, currentY, n, m) || visited[currentX][currentY])
    {
        return false;
    }
    if (currentPathIdx == strlen(word))
    {
        currentPath[currentPathIdx] = '\0';
        return strcmp(word, currentPath) == 0;
    }
    visited[currentX][currentY] = true;
    currentPath[currentPathIdx++] = matrix[currentX][currentY];
    bool pathFound = findWord(matrix, n, m, word, visited, currentX + 1, currentY, currentPath, currentPathIdx) ||
                     findWord(matrix, n, m, word, visited, currentX - 1, currentY, currentPath, currentPathIdx) ||
                     findWord(matrix, n, m, word, visited, currentX, currentY + 1, currentPath, currentPathIdx) ||
                     findWord(matrix, n, m, word, visited, currentX, currentY - 1, currentPath, currentPathIdx);

    visited[currentX][currentY] = false;
    return pathFound;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    char **matrix = new char *[n];
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new char[m];
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    bool **visited = new bool *[n];
    for (size_t i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    const int MAX_WORD_SIZE = 16;
    char word[MAX_WORD_SIZE], currentPath[MAX_WORD_SIZE];
    std::cin.ignore();
    std::cin.getline(word, MAX_WORD_SIZE);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (findWord(matrix, n, m, word, visited, i, j, currentPath, 0))
            {
                std::cout << "true\n";
                break;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}