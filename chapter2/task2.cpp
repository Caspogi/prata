#include "title2.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void farlongToYard()
{
    const int yards = 220;
    double farlong;
    cin >> farlong;

    cout << farlong << " farlongs is " << farlong * yards << " yards.";
    cout << endl;
}
