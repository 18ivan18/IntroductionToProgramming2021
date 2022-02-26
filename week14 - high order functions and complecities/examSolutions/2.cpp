#include <iostream>
#include <cstring>
#include <cassert>
#include <iomanip>

const char *strings[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "plus", "minus", nullptr};
const char *digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", nullptr};
const char *operations[] = {"plus", "minus", nullptr};
const char signs[] = {'+', '-'};
const int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool contains(const char *dict[], const char *word)
{
    while (*dict)
    {
        if (strcmp(*dict, word) == 0)
        {
            return true;
        }
        dict++;
    }
    return false;
}

char **tokenize(const char *input)
{
    char word[6];
    int count = 0, size = strlen(input), counter = 0, i = 0;
    while (i <= size)
    {
        if (counter == 3 || counter == 4 || counter == 5)
        {
            int magic = counter;
            strncpy(word, input + i - counter, counter);
            word[counter] = '\0';
            if (contains(strings, word))
            {
                counter = 0;
                count++;
                continue;
            }
        }
        counter++;
        i++;
    }

    char **result = new char *[count + 1];
    int resultIndex = 0;
    i = counter = 0;
    while (i <= size)
    {
        if (counter == 3 || counter == 4 || counter == 5)
        {
            strncpy(word, input + i - counter, counter);
            word[counter] = '\0';
            if (contains(strings, word))
            {
                counter = 0;
                result[resultIndex] = new char[strlen(word)];
                strcpy(result[resultIndex++], word);
                continue;
            }
        }
        if (counter == 5)
        {
            throw std::invalid_argument("String is invalid");
        }
        counter++;
        i++;
    }
    result[resultIndex] = nullptr;
    return result;
}

bool isValid(const char *input)
{
    char **tokens;
    try
    {
        tokens = tokenize(input);
        char *first = nullptr, *second = *tokens;
        while (true)
        {
            if (!second)
            {
                if (contains(operations, first))
                {
                    throw std::invalid_argument("Last word can't be an operation");
                }
                break;
            }
            if (!first)
            {
                if (contains(operations, second))
                {
                    throw std::invalid_argument("First word can't be an operation");
                }
            }
            else if (contains(operations, first) && contains(operations, second))
            {
                throw std::invalid_argument("Two operations cannot be next to eachother");
            }
            first = second;
            second = *(++tokens);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

void apply(int &sum, int number, char sign)
{
    switch (sign)
    {
    case '+':
        sum += number;
        break;
    case '-':
        sum -= number;
        break;

    default:
        break;
    }
}

char operationToSign(char *operation)
{
    for (int i = 0; operations[i]; i++)
    {
        if (strcmp(operations[i], operation) == 0)
        {
            return signs[i];
        }
    }
    throw std::invalid_argument("Invalid input, please validate first");
}

int stringToDigit(char *digit)
{
    for (int i = 0; digits[i]; i++)
    {
        if (strcmp(digits[i], digit) == 0)
        {
            return numbers[i];
        }
    }
    throw std::invalid_argument("Invalid input, please validate first");
}

int countDigit(long long n)
{
    int count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return count;
}

void calculateExpr(char *&input)
{
    char **tokens = tokenize(input);
    int sum = 0, number = 0;
    char sign = '+';
    while (true)
    {
        if (*tokens == nullptr)
        {
            apply(sum, number, sign);
            break;
        }
        if (contains(operations, *tokens))
        {
            apply(sum, number, sign);
            sign = operationToSign(*tokens);
            number = 0;
        }
        else
        {
            number = number * 10 + stringToDigit(*tokens);
        }
        tokens++;
    }
    delete[] input;
    int size = countDigit(sum), i = 0;
    if (sum < 0)
    {
        size++;
        i++;
    }
    input = new char[size + 1];
    if (sum < 0)
    {
        input[0] = '-';
        sum *= -1;
    }
    input[size] = '\0';
    while (i < size)
    {
        input[--size] = sum % 10 + '0';
        sum /= 10;
    }
}

void runTests()
{
    assert(contains(digits, "one"));
    assert(contains(digits, "nine"));
    assert(!contains(digits, "plus"));
    assert(isValid("onetwominusonethree"));
    assert(!isValid("oneminustwothreeplusfourfivesixplus"));
    assert(!isValid("oneminustwot1hreeplusfourfivesixplus"));
    assert(!isValid("minusoneminustwothreeplusfourfivesixplus"));
    assert(!isValid("asafdfas"));

    char input[] = "onetwominusonethree";
    char *test1 = new char[strlen(input) + 1];
    strcpy(test1, input);
    calculateExpr(test1);
    assert(strcmp(test1, "-1") == 0);

    char input1[] = "oneminustwothreeplusfourfivesix";
    char *test2 = new char[strlen(input1) + 1];
    strcpy(test2, input1);
    calculateExpr(test2);
    assert(strcmp(test2, "434") == 0);

    char input2[] = "sixnineminusfourtwozeroplusonezerozero";
    char *test3 = new char[strlen(input2) + 1];
    strcpy(test3, input2);
    calculateExpr(test3);
    assert(strcmp(test3, "-251") == 0);
    std::cout << "All tests passed successfully\n";
}

int main()
{
    runTests();
}