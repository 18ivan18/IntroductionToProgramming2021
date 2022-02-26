#include <iostream>

bool outOfBounds(int x, int y, int n)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

bool capacityValid(int capacity, int max)
{
    return capacity >= 0 && capacity <= max;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// those should be more parameters to the backtracking func
int homeRow = 1, homeColumn = 1, pathX[128 * 128], pathY[128 * 128], pathIndex = 0;

bool foundRoute(int **map, int n, int currentX, int currentY, int targetX, int targetY, int maxCapacity, int capacity, bool **visited)
{
    if (outOfBounds(currentX, currentY, n))
    {
        return false;
    }
    if (currentX == targetX && currentY == targetY)
    {
        if (visited[targetX][targetY])
        {
            // std::cout << "(" << currentX << "," << currentY << ") ";
            pathX[pathIndex] = currentX;
            pathY[pathIndex] = currentY;
            pathIndex++;
            return true;
        }
        else
        {
            targetX = homeRow;
            targetY = homeColumn;
        }
    }
    capacity += map[currentX][currentY];
    if (!capacityValid(capacity, maxCapacity) || visited[currentX][currentY])
    {
        return false;
    }
    visited[currentX][currentY] = true;
    for (size_t i = 0; i < 4; i++)
    {
        pathX[pathIndex] = currentX;
        pathY[pathIndex] = currentY;
        pathIndex++;
        if (foundRoute(map, n, currentX + dx[i], currentY + dy[i], targetX, targetY, maxCapacity, capacity, visited))
        {
            // std::cout << "(" << currentX << "," << currentY << ") ";
            return true;
        }
        pathIndex--;
    }
    visited[currentX][currentY] = false;
    return false;
}

int main()
{
    int n;
    std::cin >> n;
    int **map = new int *[n];
    for (size_t i = 0; i < n; i++)
    {
        map[i] = new int[n];
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    int grannyRow = 4, grannyColumn = 3, maxCapacity = 15;
    // std::cin >> homeRow >> homeColumn >> grannyRow >> grannyColumn >> maxCapacity;
    bool **visited = new bool *[n];
    for (size_t i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (size_t j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    std::cout << std::boolalpha << foundRoute(map, n, homeRow, homeColumn, grannyRow, grannyColumn, maxCapacity, 0, visited) << '\n';
    for (size_t i = 0; i < pathIndex; i++)
    {
        std::cout << "(" << pathX[i] << "," << pathY[i] << ") ";
    }
    std::cout << std::endl;

    // del
}