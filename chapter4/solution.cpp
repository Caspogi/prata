#include "solution.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::array;

struct CandyBar
{
    string name;
    float weight;
    short callory;
};

struct Pizza
{
    string name;
    short diameter;
    float weight;
};

void task1()
{
    setlocale(LC_ALL, "");

    cout << "Введите Имя Отчество: ";
    string firstName;
    getline(cin, firstName);

    cout << "Введите Фамилию: ";
    string lastName;
    getline(cin, lastName);

    cout << "Введите Ваш возраст: ";
    int age;
    cin >> age;

    cout << "На какую оценку Вы себя оцените: ";
    char mark;
    cin >> mark;
    mark++;

    cout << "Имя: " << lastName << ", " << firstName << endl;
    cout << "Оценка: " << mark << endl;
    cout << "Возраст: " << age << endl;
}

void task2()
{
    string name, dessert;

    cout << "Enter your name:" << endl;
    getline(cin, name);
    cout << "Enter your favorite dessert:" << endl;
    getline(cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << "." << endl;
}

void task3()
{
    cout << "Enter your first name: ";
    char firstName[50];
    cin.getline(firstName, 49);

    cout << "Enter your last name: ";
    char lastName[50];
    cin.getline(lastName, 49);

    cout << "Here's the infomation in a single string: " << firstName << ", "
         << lastName << endl;
}

void task4()
{
    string firstName, lastName;

    cout << "Enter your first name: ";
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    cout << "Here's the infomation in a single string: " << firstName << ", "
         << lastName << endl;
}

void task5()
{
    CandyBar snack{"Mocha Much", 2.3, 350};
    cout << snack.name << ", " << snack.weight << ", " << snack.callory << '.' << endl;
}

void task6()
{
    const int n = 3;
    CandyBar CandyBarArray[n]
    {
        {"Mocha Much", 2.3, 350},
        {"Mocha Mucha", 2.7, 670},
        {"Mocha Muchy", 2.56, 400}
    };
    cout << CandyBarArray->name << ", " << CandyBarArray->weight << ", " << CandyBarArray->callory << '.' << endl;
    cout << (CandyBarArray + 1)->name << ", " << (CandyBarArray + 1)->weight << ", " << (CandyBarArray + 1)->callory << '.' << endl;
    cout << (CandyBarArray + 2)->name << ", " << (CandyBarArray + 2)->weight << ", " << (CandyBarArray + 2)->callory << '.' << endl;
}

void task7()
{
    Pizza pizza;

    cout << "Name of company: ";
    getline(cin, pizza.name);

    cout << "Diameter: ";
    cin >> pizza.diameter;

    cout << "Weight: ";
    cin >> pizza.weight;

    cout << pizza.name << ", " << pizza.diameter << ", " << pizza.weight << "." << endl;
}

void task8()
{
    Pizza * pPizza = new Pizza;

    cout << "Name of company: ";
    getline(cin, pPizza->name);

    cout << "Diameter: ";
    cin >> pPizza->diameter;

    cout << "Weight: ";
    cin >> pPizza->weight;

    cout << pPizza->name << ", " << pPizza->diameter << ", " << pPizza->weight << "." << endl;
    delete pPizza;
}

void task9()
{
    const int n = 3;
    CandyBar * pCandyBarArray = new CandyBar[n]
    {
        {"Mocha Much", 2.3, 350},
        {"Mocha Mucha", 2.7, 670},
        {"Mocha Muchy", 2.56, 400}
    };
    cout << pCandyBarArray->name << ", " << pCandyBarArray->weight << ", " << pCandyBarArray->callory << '.' << endl;
    cout << (pCandyBarArray + 1)->name << ", " << (pCandyBarArray + 1)->weight << ", " << (pCandyBarArray + 1)->callory << '.' << endl;
    cout << (pCandyBarArray + 2)->name << ", " << (pCandyBarArray + 2)->weight << ", " << (pCandyBarArray + 2)->callory << '.' << endl;
    delete [] pCandyBarArray;
}

void task10()
{
    const int n = 3;
    array<float, n> arr;

    cout << "Enter 1'st run's resut: ";
    cin >> arr.at(0);

    cout << "Enter 2'nd run's resut: ";
    cin >> arr.at(1);

    cout << "Enter 3'rd run's resut: ";
    cin >> arr.at(2);

    cout << arr.at(0) << ", " << arr.at(1) << ", " << arr.at(2) << ", " << (arr.at(0) + arr.at(1) + arr.at(2)) / n << endl;
}
