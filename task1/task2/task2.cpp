// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "input year\n";

    int year;

    std::cin >> year;

    if (year % 4 == 0) {
        std::cout << "yes";
    }
    else {
        std::cout << "no";
    }
}