#include <iostream>
#include <cmath>

int main()
{
    int n, m;
    std::cin >> n >> m;
    if (n > m)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    int sum;
    for (int i = n; i < m; i++)
    {
        int curr = i;
        sum = 0;
        int numberOfDigits = 0;
        while (curr > 0)
        {
            curr /= 10;
            numberOfDigits++;
        }
        curr = i;
        while (curr > 0)
        {
            sum += pow(curr % 10, numberOfDigits);
            curr /= 10;
        }
        if (sum == i)
        {
            std::cout << i << std::endl;
        }
    }
}