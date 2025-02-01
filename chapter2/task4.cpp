#include "title2.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ageToMonth()
{
    const int month = 12;
    int age;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Your age in months is " << age * month << "." << endl;
}
