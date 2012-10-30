#include <iostream>
using std::cout;
using std::endl;

int square(int x)
{
    cout << "square of integer " << x << " is ";
    return x * x;
}

double square(double x)
{
    cout << "square of double " << x << " is ";
    return x * x;
}

int main()
{
    cout << square(7) << endl;
    cout << square(7.5) << endl;
    return 0;
}
