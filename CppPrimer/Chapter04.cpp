#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const size_t array_size = 10;
    int ia[array_size];

    for (size_t i = 0; i != array_size; ++i)
        ia[i] = i * i;

    int *pia = NULL;
    pia = ia;

    cout << *(pia + 5) << endl;

    int *pia2 = &ia[8];
    ptrdiff_t n = pia2 - pia;
    cout << "n = " << n << endl;

    const char *cp = "changxy";
    cout << *cp << endl;
    while (*(cp++ + 1))
        cout << *cp << endl;

    pia = new int[15];
    delete [] pia;

    return 0;
}