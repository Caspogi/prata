#include "title2.hpp"
#include <iostream>

using std::cout;
using std::endl;

void time(int hours, int minutes)
{
    hours += minutes / 60;
    minutes = minutes % 60;
    hours %= 24;

    cout << "Time: " << hours << ':' << minutes << endl;
}
