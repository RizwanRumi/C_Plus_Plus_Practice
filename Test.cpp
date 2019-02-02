#include<iostream>

#define LIMIT 5
#define AREA(l, b) (l * b)
using namespace std;

int main()
{
//    for(int i = 0; i<LIMIT; i++)
//    {
//        std::cout <<i << "\n";
//    }

    int l_1 = 10, l_2 = 5, area;

    area = AREA(l_1, l_2);

    std::cout << area << "\n";

    return 0;
}
