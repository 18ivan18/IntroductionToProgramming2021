#include <iostream>
#include <cstring>

int patternMatchingIndex(const char *const str1, const char *const str2)
{
    int size1 = strlen(str1), size2 = strlen(str2);
    for (int i = 0; i <= size1 - size2; i++)
    {
        int j;
        for (j = 0; j < size2; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
        }
        if (j == size2)
        {
            return i;
        }
    }
    return -1;
}

int replace(char *text, const char *const str1, const char *const str2)
{
    int matchIndex, size1 = strlen(str1), size2 = strlen(str2), sizeText = strlen(text), offset = 0, replaceCounter = 0;
    while ((matchIndex = patternMatchingIndex(text + offset, str1)) != -1)
    {
        matchIndex += offset;
        replaceCounter++;
        for (int i = sizeText - matchIndex - size1; i >= 0; i--)
        {
            text[matchIndex + size2 + i] = text[matchIndex + size1 + i];
        }
        strncpy(text + matchIndex, str2, size2);
        offset = matchIndex + size2;
        sizeText += size2 - size1;
    }
    return replaceCounter;
}

const int KB = 1 << 10;
#include <cassert>
void runTests()
{
    char text[KB << 2] = "axc";
    assert(replace(text, "x", "b") == 1);
    assert(strcmp(text, "abc") == 0);

    char text1[KB << 2] = "My name is who?";
    assert(replace(text1, "who?", "Chica-chica Slim Shady!") == 1);
    assert(strcmp(text1, "My name is Chica-chica Slim Shady!") == 0);

    char text2[KB << 2] = "aabbaaaa";
    assert(replace(text2, "aa", "bb") == 3);
    assert(strcmp(text2, "bbbbbbbb") == 0);

    char text3[KB << 2] = "I wanna break free!";
    assert(replace(text3, "I", "You") == 1);
    assert(strcmp(text3, "You wanna break free!") == 0);

    char text4[KB << 2] = "I really like eating a banana, but bananas make me puke.";
    assert(replace(text4, "banana", "super big banana") == 2);
    assert(strcmp(text4, "I really like eating a super big banana, but super big bananas make me puke.") == 0);

    std::cout << "All tests ran successfully\n";
}

int main()
{
    runTests();
    char str1[KB], str2[KB], text[KB << 2];
    std::cin.getline(text, KB << 2);
    std::cin.getline(str1, KB);
    std::cin.getline(str2, KB);
    std::cout << replace(text, str1, str2) << " " << text << '\n';
}