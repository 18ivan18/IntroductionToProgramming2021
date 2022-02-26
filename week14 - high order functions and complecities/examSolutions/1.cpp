#include <iostream>
#include <cstring>

int playGame(char *colors, int begin)
{
    int size = strlen(colors);
    int turns = 0;
    for (size_t i = begin; i < size; i++)
    {
        switch (colors[i])
        {
        case 'y':
            while (i < size && colors[i] != 'g')
            {
                i++;
            }
            if (i == size)
            {
                return turns;
            }
            i--;
        case 'g':
            turns++;
            break;

        default:
            return turns;
        }
    }
    return turns;
}

int main()
{
    const int MAX_SIZE = 1024;
    char colors[MAX_SIZE];
    std::cin.getline(colors, MAX_SIZE);
    int size = strlen(colors);
    for (size_t i = 0; i < size; i++)
    {
        if (colors[i] != 'g' && colors[i] != 'y' && colors[i] != 'r')
        {
            throw std::invalid_argument("Invalid input");
        }
    }
    int max = 0, start = -1;
    for (size_t i = 0; i < size; i++)
    {
        int play = playGame(colors, i);
        if (play > max)
        {
            max = play;
            start = i;
        }
    }
    std::cout << max << " " << start << '\n';
}