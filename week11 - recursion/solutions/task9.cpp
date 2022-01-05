#include <iostream>
#include <cstring>

bool isPalindromeRec(char *str, int l, int r)
{
    if (l == r)
    {
        return true;
    }

    if (str[l] != str[r])
    {
        return false;
    }

    if (l < r + 1)
    {
        return isPalindromeRec(str, l + 1, r - 1);
    }

    return true;
}

int main()
{
    char pal[] = "bqlhlqb";

    std::cout << std::boolalpha << isPalindromeRec(pal, 0, strlen(pal) - 1) << std::endl;
}