#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int ans = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
        {
            ans++;
        }
        n = n >> 1;
    }
    std::cout << ans << std::endl;
}