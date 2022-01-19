/*Алгебричен израз е зададен с низ, състоящ се от малки латински букви, разделени с единичен знак '.' (умножение) или '+' (събиране). 
Всяка буква означава цяло число, като съответствието е зададено с два масива от n букви letters и n числа values, като на буквата letters[i] 
съответства числото values[i]. Да се реализира функция calculate, която приема коректно зададен израз, число n и масиви letters и values и
връща пресметнатата стойността на израза, спазвайки приоритета на операциите. Ако в израза се среща латинска буква, за която не е зададена стойност, тя да се приеме за 0.
Упътване: Можете да използвате една променлива, която натрупва текущото произведение и една променлива, която натрупва общата сума.

*/
#include <cassert>
#include <cstring>
#include <iostream>

int getVal(char arg, int n, const char *letters, int *values)
{
    for (size_t i = 0; i < n; i++)
    {
        if (letters[i] == arg)
        {
            return values[i];
        }
    }

    return 0;
}

int calculate(const char *str, int n, const char *letters, int *values)
{
    char op;
    int sum = 0, prod = 1, i = 0;

    while (str[i])
    {
        prod = getVal(str[i++], n, letters, values);
        op = str[i++];
        while (str[i] && op == '.')
        {
            prod *= getVal(str[i++], n, letters, values);
            op = str[i++];
        }
        sum += prod;
    }

    return sum;
}

int main()
{
    char letters[] = {'b', 'c', 'a', 'd'};
    int values[] = {5, 3, 2, 42};
    int size = sizeof(letters) / sizeof(letters[0]);
    assert(calculate("a+b", size, letters, values) == 7);
    assert(calculate("a.b", size, letters, values) == 10);
    assert(calculate("a.b+b.c+d+a.c", size, letters, values) == 73);
    char letters1[] = {'d', 'e', 'h', 'l', 'o', 'r'};
    int values1[] = {3, 2, 3, 1, 5, 10};
    int size1 = sizeof(letters1) / sizeof(letters1[0]);
    assert(calculate("h.e.l.l.o+w.o.r.l.d", size1, letters1, values1) == 30);
}