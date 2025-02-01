#include "solution.hpp"
#include <cctype>
#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::string;
using std::ifstream;
using std::vector;
using std::getline;

const int STRSIZE = 128;

struct Bop
{
    char fullname[STRSIZE];
    char title[STRSIZE];
    char bopname[STRSIZE];
    int preference;
};

struct Mecenat
{
    string name;
    double payment;
};

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

void task4()
{
    const int BOPSIZE = 5;

    array<Bop, BOPSIZE> bops
    {{
        {"Bob", "Midle", "Boby", 2},
        {"Piter", "Junior", "Stenly", 1},
        {"Stan", "Junior", "Orb", 1},
        {"Olga", "Senior", "MegaO", 0},
        {"Janny", "Team leader", "MegaDrive", 2},
    }};

    cout << "a. display by name\tb. display by title\n"
            "c. display by bopname\td. display by preference\n"
            "q. quit" << endl;

    cout << "Enter your choice: ";
    char c;

    cin >> c;
    while (c != 'q')
    {
        switch (c)
        {
            case 'a':
                for (auto bop : bops)
                    cout << bop.fullname << endl;
                break;

            case 'b':
                for (auto bop : bops)
                    cout << bop.title << endl;
                break;

            case 'c':
                for (auto bop : bops)
                    cout << bop.bopname << endl;
                break;

            case 'd':
                for (auto bop : bops)
                    switch (bop.preference)
                    {
                        case 0:
                            cout << bop.fullname << endl;
                            break;

                        case 1:
                            cout << bop.title << endl;
                            break;

                        case 2:
                            cout << bop.bopname << endl;
                            break;
                    }
                break;
        }

    cout << "Enter your choice: ";
    cin >> c;
    }

    cout << "Bye!" << endl;
}

void task5()
{
    const double ZERO = 0;
    const double ONE = 0.10;
    const double TWO = 0.15;
    const double TREE = 0.20;
    const int TWOTRAPS = 20000;
    const int ONETRAPS = 10000;
    const int ZEROTRAPS = 5000;
    const int TREETRAPS = 35000;

    int tip = 0;
    double traps, sum = 0, tips = 0;
    cin >> traps;

    while (traps >= 0 && cin)
    {
        sum += traps;
        cin >> traps;
    }

    while (sum > 0)
    {
        if (tip == 0)
        {
            if (sum - ZEROTRAPS > 0 )
            {
                tips += ZEROTRAPS * ZERO;
                sum -= ZEROTRAPS;
                tip++;
            }
            else
            {
                tips += sum * ZERO;
                sum = 0;
            }

        }
        else if (tip == 1)
        {
            if (sum - ONETRAPS > 0 )
            {
                tips += ONETRAPS * ONE;
                sum -= ONETRAPS;
                tip++;
            }
            else
            {
                tips += sum * ONE;
                sum = 0;
            }
        }
        else if (tip == 2)
        {
            if (sum - TWOTRAPS > 0 )
            {
                tips += TWOTRAPS * TWO;
                sum -= TWOTRAPS;
                tip++;
            }
            else
            {
                tips += sum * TWO;
                sum = 0;
            }
        }
        else
        {
            tips += sum * TREE;
            sum = 0;
        }
    }

    cout << "Налог за год: " << tips << endl;
}

void task6()
{
    int n;
    cout << "Введите количество меценатов: ";
    cin >> n;
    Mecenat* mecenat = new Mecenat[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Имя мецената №" << i + 1 << ": ";
        cin >> (mecenat + i)->name;
        cout << "Сумма пожертвования мецената №" << i + 1 << ": ";
        cin >> (mecenat + i)->payment;
    }

    bool ok = true;
    cout << "Grand Patrons" << endl;
    for (int i = 0; i < n; i++)
    {
        if ((mecenat + i)->payment >= 10000)
        {
            ok = false;
            cout << (mecenat + i)->name << " " << (mecenat + i)->payment << endl;
        }

    }
    if (ok) cout << "none" << endl;

    cout << "Patrons" << endl;
    ok = true;
    for (int i = 0; i < n; i++)
    {
        if ((mecenat + i)->payment < 10000)
        {
            ok = false;
            cout << (mecenat + i)->name << " " << (mecenat + i)->payment <<endl;
        }
    }
    if (ok) cout << "none" << endl;

    delete [] mecenat;
}

void task7()
{
    const string VOWELS = {"aeuio"};

    cout << "Enter words (q to quit):" << endl;
    int countVowels = 0, countConsonants = 0, countOther = 0;
    string word;
    cin >> word;
    while (word != "q")
    {
        if (isalpha(word[0]))
            if (VOWELS.find(word[0]) == -1)
                countConsonants++;
            else
                countVowels++;
        else countOther++;
        cin >> word;
    }

    cout << countVowels << " words beginning with vowels" << endl;
    cout << countConsonants << " words beginning with consonants" << endl;
    cout << countOther << " othes" << endl;
}

void task8()
{
    ifstream in;
    in.open("out.txt");
    if (!in.is_open())
    {
        cout << "Всё плохо!" << endl;
        exit(EXIT_FAILURE);
    }

    char c;
    int count = 0;
    in.get(c);
    while (in.good())
    {
        count++;
        in.get(c);
    }
    in.close();

    cout << "Количество символов в файле: " << count << endl;

}

void task9()
{
    ifstream in;
    in.open("in.txt");
    if (!in.is_open())
    {
        cout << "Всё плохо!" << endl;
        exit(EXIT_FAILURE);
    }

    int n = 0;
    (in >> n).get();
    if (n == 0 || in.eof())
    {
        cout << "Файл пуст" << endl;
        exit(EXIT_FAILURE);
    }
    else if (in.fail())
    {
        cout << "Ввод прекращен из-за несоответствия типов";
        exit(EXIT_FAILURE);
    }

    vector<Mecenat> mecenat(n);
    for (int i = 0; i < n; i++)
    {
        getline(in, mecenat[i].name);

        (in >> mecenat[i].payment).get();
    }

    in.close();

    bool ok = true;
    cout << "Grand Patrons" << endl;
    for (int i = 0; i < n; i++)
    {
        if (mecenat[i].payment >= 10000)
        {
            ok = false;
            cout << mecenat[i].name << " " << mecenat[i].payment << endl;
        }

    }
    if (ok) cout << "none" << endl;

    cout << "Patrons" << endl;
    ok = true;
    for (int i = 0; i < n; i++)
    {
        if (mecenat[i].payment < 10000)
        {
            ok = false;
            cout << mecenat[i].name << " " << mecenat[i].payment << endl;
        }
    }
    if (ok) cout << "none" << endl;
}
