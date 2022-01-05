#include <iostream>
#include <cstring>

bool isDigit(char a)
{
    return a >= '0' && a <= '9';
}
// 0 * 10 + 1 => 1 * 10 + 2 => 12 * 10 + 3 => 123
int stoi(char *str, int i)
{
    if (i == 1)
    {
        return *str - '0';
    }

    return (10 * stoi(str, i - 1) + str[i - 1] - '0');
    // 10 * (10 * (1) + 2) + 3
}

int getNumber(char *str, int &i)
{
    char number[10];
    int charIndex = 0;
    while (isdigit(str[i]))
    {
        number[charIndex++] = str[i];
        i++;
    }
    number[charIndex] = '\0';
    int result = stoi(number, strlen(number));
    return result;
}

int apply(char op, int larg, int rarg)
{
    switch (op)
    {
    case '+':
        return larg + rarg;
    case '*':
        return larg * rarg;
    default:
        break;
    }
    return 0;
}

int calculateRec(char *str, int &i)
{
    int larg, rarg;
    char op;

    if (str[i] == '(')
    {
        i++;
        larg = calculateRec(str, i);
    }

    if (isdigit(str[i]))
    {
        larg = getNumber(str, i);
    }

    if (str[i] == ')' || str[i] == '\0')
    {
        i++;
        return larg;
    }
    op = str[i++];
    rarg = calculateRec(str, i);

    return apply(op, larg, rarg);
}

int calculate(char *str)
{
    int index = 0;
    return calculateRec(str, index);
}

int main()
{
    // const int MAX_SIZE = 64;
    // char input[MAX_SIZE];
    // std::cin.getline(input, MAX_SIZE);

    char example1[] = "(2+3*((1+4)*5)+7)";
    char example2[] = "2+(3*2)+7";
    char example3[] = "(25*3)+(5+6)";

    std::cout << calculate(example1) << std::endl; // 98
    std::cout << calculate(example2) << std::endl; // 15
    std::cout << calculate(example3) << std::endl; // 86

    // std::cout << calculate(input) << std::endl;
}