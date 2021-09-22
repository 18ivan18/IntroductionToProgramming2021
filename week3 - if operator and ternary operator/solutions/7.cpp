#include <iostream>
#include <iomanip>

int main()
{
    int marks;
    double grade;
    std::cin >> marks;
    if (marks >= 0 && marks < 25)
    {
        grade = 2;
    }
    else if (marks >= 25 && marks < 40)
    {
        grade = 3;
    }
    else if (marks >= 40 && marks < 60)
    {
        grade = 4;
    }
    else if (marks >= 60 && marks < 80)
    {
        grade = 5;
    }
    else if (marks >= 80 && marks < 100)
    {
        grade = 6;
    }
    else
    {
        std::cout << "Invalid marks" << std::endl;
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2) << grade << std::endl;
}