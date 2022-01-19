/*
Да се реализира функция minWord, която приема като параметър низ и връща указател към началото на лексикографски най-малка непразна дума в него. 
Дума е непрекъсната последователност от малки и големи латински букви и цифри, всички останали символи се считат за разделители.

*/
#include <iostream>
#include <cassert>

const int KB = 1 << 10;

bool lexicographicalCompare(char *first1, char *last1,
                            char *first2, char *last2)
{
    for (; (first1 != last1) && (first2 != last2); first1++, first2++)
    {
        if (*first1 < *first2)
        {
            return true;
        }
        if (*first2 < *first1)
        {
            return false;
        }
    }
    return (first1 == last1) && (first2 != last2);
}

char *minWord(char *curr)
{
    char *minWordStart, *minWordEnd, *tempStart;
    int index;
    while (*curr)
    {
        if (isalpha(*curr))
        {
            minWordStart = curr;
            while (isalpha(*curr))
            {
                curr++;
            }
            minWordEnd = curr;
            break;
        }
        else
        {
            curr++;
        }
    }

    while (*curr)
    {
        if (isalpha(*curr))
        {
            tempStart = curr;
            while (isalpha(*curr))
            {
                curr++;
            }
            if (lexicographicalCompare(minWordStart, minWordEnd, tempStart, curr))
            {
                minWordStart = tempStart;
                minWordEnd = curr;
            }
        }
        else
        {
            curr++;
        }
    }

    return minWordStart;
}

int main()
{
    char word[KB];
    std::cin.getline(word, KB);
    std::cout << minWord(word) << '\n';
}