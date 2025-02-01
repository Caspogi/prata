#include <iostream>

void cheese(int);

int main()
{
    cheese(5);
    return 0;
}

void cheese(int n)
{
    for (int i = 0; i < n; i++)
        std::cout << "Cheese!" << std::endl; 
}
