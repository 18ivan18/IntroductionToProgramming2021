/*
Дадена е квадратна матрица matrix от цели числа с размерност n × n, за 1 ≤ n ≤ 30.
 Да се реализира функция collect, която приема matrix и числото n връща едномерен масив, съдържащ онези елементи на матрицата, в десетичния запис на които има повтарящи се цифри. 
 Едномерният масив трябва да бъде динамично заделен, с точно толкова елемента, колкото трябва да се съхраняват в него. Да се реализира програма, 
 която въвежда от стандартния вход квадратна матрица, извиква функцията collect по подходящ начин и извежда върнатия като резултат масив на стандартния изход.
Добавянето на елементите трябва да става спрямо техния ред при обхождането на матрицата по диагоналите успоредни на главния диагонал, започвайки от долния ляв ъгъл, с
ъгласно схемата по-долу:
*/
#include <iostream>

const int NUMERAL_SYSTEM = 10;

bool hasRepeatingDigits(int n)
{
    int histo[NUMERAL_SYSTEM] = {0};
    while (n)
    {
        histo[n % NUMERAL_SYSTEM]++;
        n /= NUMERAL_SYSTEM;
    }
    for (size_t i = 0; i < NUMERAL_SYSTEM; i++)
    {
        if (histo[i] > 1)
        {
            return true;
        }
    }

    return false;
}

bool goDiag(int &x, int &y, const int &n)
{
    x++;
    y++;
    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        return false;
    }
    return true;
}

int *collect(int **matrix, int n, int &sizeOfRes)
{
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = i, y = 0;
        do
        {
            // std::cout << matrix[x][y] << '\n';
            if (hasRepeatingDigits(matrix[x][y]))
            {
                cnt++;
            }
        } while (goDiag(x, y, n));
    }
    for (int i = 1; i < n; i++)
    {
        int x = 0, y = i;
        do
        {
            // std::cout << matrix[x][y] << '\n';
            if (hasRepeatingDigits(matrix[x][y]))
            {
                cnt++;
            }
        } while (goDiag(x, y, n));
    }

    sizeOfRes = cnt;
    int *res = new int[sizeOfRes];
    int idx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = i, y = 0;
        do
        {
            if (hasRepeatingDigits(matrix[x][y]))
            {
                res[idx++] = matrix[x][y];
            }
        } while (goDiag(x, y, n));
    }

    for (int i = 1; i < n; i++)
    {
        int x = 0, y = i;
        do
        {
            if (hasRepeatingDigits(matrix[x][y]))
            {
                res[idx++] = matrix[x][y];
            }
        } while (goDiag(x, y, n));
    }
    return res;
}

int main()
{
    int **matrix;
    int n;
    std::cin >> n;
    matrix = new int *[n];
    for (size_t i = 0; i < n; i++)
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
    int sizeOfRes, *res = collect(matrix, n, sizeOfRes);
    for (size_t i = 0; i < sizeOfRes; i++)
    {
        std::cout << res[i] << " ";
    }
}