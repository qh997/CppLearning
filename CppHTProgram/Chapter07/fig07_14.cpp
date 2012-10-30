#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

void modifyArray(int [], int);
void modifyElement(int);

int main()
{
    const int arraySize = 5;
    int a[arraySize] = {0,1,2,3,4};

    cout << "Effects of passing entrie array by reference:\n\n"
         << "The value of the original array are:\n";
    for (int i = 0; i < arraySize; ++i)
        cout << setw(3) << a[i];
    cout << endl;

    modifyArray(a, arraySize);
    cout << "The value of the modifyied array are:\n";
    for (int i = 0; i < arraySize; ++i)
        cout << setw(3) << a[i];
    cout << endl;

    cout << "\n\nEffects of passing array element by value:\n\n";
    cout << "a[3] before modifyElement: " << a[3] << endl;
    modifyElement(a[3]);
    cout << "a[3] after modifyElement: " << a[3] << endl;

    return 0;
}

void modifyArray(int b[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i)
        b[i] *= 2;
}

void modifyElement(int e)
{
    cout << "Vale of element in modifyElement: " << (e *= 2)
         << endl;
}
