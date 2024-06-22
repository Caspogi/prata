#include "solution.hpp"
#include <iostream>
#include <fstream>

using std::ofstream;

int main()
{
    ofstream outFile;
    outFile.open("out.txt");

    double x = 0.1;
    outFile << x << std::endl;
    outFile.close();
    return 0;
}
