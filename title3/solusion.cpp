#include "solusion.hpp"
#include <iostream>

const int INCHS = 12;
const float METRES = 0.0254f;
const float POUNDS = 2.2f;

using std::cout;
using std::cin;
using std::endl;

void inchToFoot()
{
    setlocale(LC_ALL, "");
    cout << "Введите рост в дюймах:___\b\b\b";

    int inchs;
    int foots;

    cin >> inchs;

    foots = inchs / INCHS;
    inchs %= INCHS;

    cout << "Рост: " << foots << "' " << inchs << "''" << endl;
}


void bodyMassIndex()
{
    setlocale(LC_ALL, "");

    cout << "Введите рост\n" << "Футы:___\b\b";
    int foots;
    cin >> foots;

    cout << "Дюймы:___\b\b" ;
    int inchs;
    cin >> inchs;

    cout << "Введите массу в фунтах:______\b\b\b\b\b";
    float mass;
    cin >> mass;

    cout << "Индекс массы тела: "
         << mass / METRES / ((inchs + foots * INCHS) * (inchs + foots * INCHS)) << endl;
}

void latitude()
{
    setlocale(LC_ALL, "");

    cout << "Введите широту в градусах минутах и секундах:" << endl;
    cout << "Сначала введите градусы: ";
    int degrees;
    cin >> degrees;

    cout << "Следующим введите минуты: ";
    int minutes;
    cin >> minutes;

    cout << "Наконец, введите секунды: ";
    int seconds;
    cin >> seconds;

    cout << degrees << " degrees, " << minutes << " minutes, "
         << seconds << " seconds = "
         << degrees + minutes / 60.0 + seconds / (60.0 * 60.0)
         << " degrees" << endl;
}

void sToDHS()
{
    const unsigned int SECONDS_TO_DAY = 86400;
    const unsigned int SECONDS_TO_HOUR = 3600;
    const unsigned int SECONDS_TO_MINUTES = 60;

    cout << "Enter the number of seconds: ";
    unsigned long long seconds;
    cin >> seconds;

    cout << seconds << " seconds = "
         << seconds / SECONDS_TO_DAY << " days, "
         << seconds % SECONDS_TO_DAY / SECONDS_TO_HOUR << " hours, "
         << (seconds % SECONDS_TO_HOUR) / SECONDS_TO_MINUTES << " minutes, "
         << seconds % SECONDS_TO_MINUTES << " seconds" << endl;
}

void population()
{
    cout << "Enter the world's populatin: ";
    unsigned long long populationOfWorld;
    cin >> populationOfWorld;

    cout << "Enter the populatin of the Russian: ";
    unsigned long long populationOfRussian;
    cin >> populationOfRussian;

    cout << "The populatin of the Russian is "
         << populationOfRussian / (populationOfWorld / 100.0)
         << "\% of the world populatin." << endl;
}

void fuelConsumption()
{
    cout << "km = ";
    float km;
    cin >> km;

    cout << "litres = ";
    float litres;
    cin >> litres;

    cout << "Fuel consumption is " << litres / km / 100.0 << endl;
}

void fuelConsumptionUS()
{
    const float LITRES = 3.875f;
    const float MILES = 0.6214f;

    cout << "km = ";
    float km;
    cin >> km;
    km *= MILES;

    cout << "litres = ";
    float litres;
    cin >> litres;
    litres /= LITRES;

    cout << "Fuel consumption is " << km / litres << endl;
}
