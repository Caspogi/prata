#include "solution.hpp"
#include <cctype>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

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
