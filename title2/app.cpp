#include "title2.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Enter the number of hours: ";
    double hours;
    cin >> hours;

    cout << "Enter the number of minutes: ";
    double minutes;
    cin >> minutes;

    time(hours, minutes);

    return 0;
}

