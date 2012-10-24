#include <iostream>
#include <iomanip>
#include <climits>
#include <limits>
#include <cstdlib>
#include <time.h>

#include "Matrix.h"

using namespace std;
using namespace Numeric_lib;

#define SHOW_VAR(var) cout << #var" = " << var << endl

int main()
{
    float x = 1.0/333;
    float sum = 0;
    for (int i = 0; i < 333; ++i)
        sum += x;
    cout << setprecision(15) << "sum = " << sum << endl;

    short int y = 40000;
    int i = 1000000;
    cout << y << " " << i*i << endl;

    cout << "number of bytes in an int: " << sizeof(int) << endl;
    cout << "largest int: " << INT_MAX << endl;
    cout << "smallest int value: " << numeric_limits<int>::min() << endl;
    if (numeric_limits<char>::is_signed)
        cout << "char is signed" << endl;
    else
        cout << "char is unsigned" << endl;

    Matrix<double, 1> ad1(5);
    ad1[3] = 3.14159;
    SHOW_VAR(ad1[3]);
    Matrix<double, 2> ad2(3, 4);
    ad2[2][3] = 2.718;
    SHOW_VAR(ad2[2][3]);

    srand(time(NULL));
    for (int i = 0; i < 3; ++i)
        SHOW_VAR(rand());
}
