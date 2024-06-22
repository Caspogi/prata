#include "solution.hpp"
#include <iostream>
#include <array>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::string;

const int COUNT_MONTH = 12;

const array<string, COUNT_MONTH> MONTH
    {
        "Январь",
        "Февраль",
        "Март",
        "Апрель",
        "Май",
        "Июнь",
        "Июль",
        "Август",
        "Сентябрь",
        "Октябрь",
        "Ноябрь",
        "Декабрь"
    };

void task1()
{
    int i, j, sum = 0;
    for (cin >> i, cin >> j; i <= j; i++)
        sum += i;
    cout << sum << endl;
}

void task2()
{
    const char ARR_SIZE = 101;

    array<long double, ARR_SIZE> factorial;
    factorial[1] = factorial[0] = 1.0L;

    for (char i = 2; i < ARR_SIZE; i++)
        factorial[i] = i * factorial[i - 1];

    cout << "100! = " << factorial[100];
}

void task3()
{
    double n = 0.0, sum = 0.0;
    cin >> n;
    while (n != 0)
    {
        sum += n;
        cout << sum << endl;
        cin >> n;
    }
}

void task4()
{
    setlocale(LC_ALL, "");

    const double simple = 0.1;
    const double difficult = 0.05;

    double dafna = 100, kleo = 100;
    double d = simple * dafna;

    for (int i = 1; kleo <= dafna; i++)
    {
        dafna += d;
        kleo += difficult * kleo;
        cout << "После " << i << "го года у Дафны: " << dafna << "$" << endl;
        cout << "После " << i << "го года у Клео: " << kleo << "$" << endl;
        cout << "-------------------------------------------------" << endl;
    }
}


void task5()
{
    setlocale(LC_ALL, "");

    array<int, COUNT_MONTH>sale;
    int sum = 0;
    for (int i = 0; i < COUNT_MONTH; i++)
    {
        cout << MONTH[i] << ": ";
        cin >> sale[i];
        sum += sale[i];
    }

    cout << sum << endl;

}

void task6()
{
    setlocale(LC_ALL, "");
    const int YEARS = 3;

    array<array<int, COUNT_MONTH>, YEARS>sale;
    array<int, YEARS>sum_year;
    int sum = 0;

    for (int y = 0; y < YEARS; y++)
    {
        sum_year[y] = 0;
        cout << "Продажи за " << y + 1 << "й год:" << endl;
        for (int i = 0; i < COUNT_MONTH; i++)
        {
            cout << MONTH[i] << ": ";
            cin >> sale[y][i];
            sum += sale[y][i];
            sum_year[y] += sale[y][i];
        }
    }
    for (int y = 0; y < YEARS; y++)
    {
        cout << "Продажи за " << y + 1 << "й год: " << sum_year[y] << endl;
    }
    cout << "Итого: " << sum << endl;
}

void task7()
{
    struct Car
    {
        string name;
        short year;
    };
    int n;

    cout << "Сколько автомобилей поместить в каталог? ";
    cin >> n;
    Car *car = new Car[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Автомобиль №" << i + 1 << ":" << endl;
        cout << "Введите производителя: ";
        cin >> car[i].name;
        cout << "Введите год выпуска: ";
        cin >> car[i].year;
    }

    cout << "Вот ваша коллекция:" << endl;
    for (int i = 0; i < n; i++)
        cout << car[i].year << " " << car[i].name << endl;
    delete [] car;
}

void task8()
{
    char word[1000];
    cin >> word;
    int count = 0;
    while (strcmp(word, "done"))
    {
        cin >> word;
        count++;
    }

    cout << "Вы ввели " << count << " cлов" << endl;
}

void task9()
{
    string word;
    cin >> word;
    int count = 0;
    while (word != "done")
    {
        cin >> word;
        count++;
    }

    cout << "Вы ввели " << count << " cлов" << endl;
}

void task10()
{
    cout << "Введите количество строк: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << '.';
        for (int j = n - i - 1; j < n; j++)
            cout << '*';
        cout << endl;
    }
}
