#include <iostream>

const int MAX_ELEMENTS = 20;
int main()
{
    int n, k;
    std::cout << "n = ";
    std::cin >> n;
    int arr[MAX_ELEMENTS];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "k = ";
    std::cin >> k;

    /*  
    //първи вариант
    int counter = -1;
    do{
        counter++;
        if(counter == k) {
            for(int i = counter; i <= n - 1; i++) {
                arr[i] = arr[i + 1];
            }
        }
    } while(counter != k && counter < n);
    */
    bool haveDeleted = false;
    for (int i = 0; i < n; i++)
    {
        if (i == k)
        {
            haveDeleted = true;
            for (int j = i + 1; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            break;
        }
    }

    if (haveDeleted)
    {
        n--;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
