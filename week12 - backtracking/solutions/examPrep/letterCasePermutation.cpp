#include <iostream>
#include <cmath>
#include <cstring>

int numberOfLetters(const char *str)
{
    int count = 0;
    while (*str)
    {
        if (isalpha(*str))
        {
            count++;
        }
        str++;
    }
    return count;
}

void addToResult(char *str, int idx, char **result, int &resultIndx)
{
    if (idx > strlen(str))
    {
        result[resultIndx] = strcpy(new char[strlen(str)], str);
        resultIndx++;
        return;
    }

    addToResult(str, idx + 1, result, resultIndx);

    if (isalpha(str[idx]))
    {
        str[idx] = toupper(str[idx]);
        addToResult(str, idx + 1, result, resultIndx);
        str[idx] = tolower(str[idx]);
    }
}

char **letterCasePermutation(char *str)
{
    int numberOfLetter = numberOfLetters(str);
    int size = pow(2, numberOfLetter);
    char **result = new char *[size + 1];
    int resultIdx = 0;
    addToResult(str, 0, result, resultIdx);
    result[size] = nullptr;
    // sort(result);
    return result;
}

#include <cassert>
void test()
{
    assert(numberOfLetters("a1b2") == 2);
}

int main()
{
    test();
    const int SIZE = 31;
    char input[SIZE];
    std::cin.getline(input, SIZE);
    char **output = letterCasePermutation(input);
    while (*output != nullptr)
    {
        std::cout << *output++ << " ";
    }
}