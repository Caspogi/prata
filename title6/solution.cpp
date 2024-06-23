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
