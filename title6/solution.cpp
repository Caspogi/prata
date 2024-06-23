#include "solution.hpp"
#include <cctype>
#include <iostream>
#include <array>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::array;

void task1()
{
    char str[1024];
    int i = 0;
    char ch;
    cin.get(ch);
    while (ch != '@')
    {
        if (islower(ch)) str[i++] = toupper(ch);
        else if (isupper(ch)) str[i++] = tolower(ch);
        else str[i++] = ch;
        cin.clear();
        cin.get(ch);
    }
    str[i] = '\0';
    cout << str << endl;
}

void task2()
{
    const int N = 10;

    array<double, N> nums;
    int i = 0;
    double num, sum = 0.0;

    while (i < N && cin >> num)
    {
        sum += num;
        nums[i] = num;
        i++;
    }

    cout << "Среднее: " << sum / i << endl;
    cout << "Числа, больше среднего: ";
    for (int j = 0; j < i; j++)
        if (nums[j] > sum / i) cout << nums[j] << " ";
    cout << endl;
}

void task3()
{
    cout << "Please enter one of the following choices:\n"
            "c) carnival\tp) pianist\n"
            "t) tree\t\tg)game" << endl;

    char c;
    cin >> c;
    while (c)
        switch (c)
        {
            case 'c':
                cout << "A maple is a carnival." << endl;
                c = 0;
                break;
            case 'p':
                cout << "A maple is a pianist." << endl;
                c = 0;
                break;
            case 't':
                cout << "A maple is a tree." << endl;
                c = 0;
                break;
            case 'g':
                cout << "A maple is a game." << endl;
                c = 0;
                break;
            default:
                cout << "Please enter a c, p, t, or g: ";
                cin >> c;
                break;
        }
}
