#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int first_number;
    int second_number;

    std::cin >> first_number >> second_number;

    //математически функции - стр. 6 от теорията
    std::cout << "сума: " << first_number + second_number << std::endl;
    std::cout << "абс. стойност: " << abs(first_number - second_number) << std::endl;
    std::cout << "остатък: " << first_number % second_number << std::endl;
    std::cout << "цяла част: " << first_number / second_number << std::endl;

    //за да може операторът "/" (за деление) да смята не целочислено деление, а това, с което сме свикнали,
    //е необходимо поне един (а може и двата) от операндите да бъде нецелочислен, т.е. double;
    //затова ни се налага преобразуване на поне единия операнд; трите начина отдолу връщат един и същи резултат
    //с разлика в това коя от двете променливи преобразуваме от int към double;
    std::cout << "частно: " << (double)first_number / second_number << std::endl;
    /*std::cout << "частно: " << a / (double)b << std::endl; 
	std::cout << "частно: " << (double)a / (double)b << std::endl;*/

    std::cout << "долна скоба: " << floor(first_number / second_number) << std::endl;
    std::cout << "горна скоба: " << ceil((double)first_number / (double)second_number) << std::endl;
    std::cout << "степенуване: " << pow(first_number, sqrt(second_number)) << std::endl;

    //функцията setprecision(int number_of_digits) ни дава извеждане на искания брой цифри след десетината запетая;
    //за да можем да я използваме, ни е необходим хедъра <iomanip>
    std::cout << "логаритмуване: " << std::fixed << std::setprecision(5) << log(floor(first_number / second_number)) / log(2) << std::endl;
    return 0;
}