#include <iostream>
#include <stdexcept>
#include "vector.h"

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

int main()
{
    SHOW_VAR(sizeof(char));
    SHOW_VAR(sizeof(int));
    SHOW_VAR(sizeof(int*));
    SHOW_VAR(sizeof(bool));
    SHOW_VAR(sizeof(double));

    vector v(5);
    for (int i = 0; i < 5; ++i)
    {
        v.set(i, 1.1 * i);
        SHOW_VAR(v.get(i));
    }

    void *pv1 = new int(997);
    int *pv2 = static_cast<int *>(pv1);
    SHOW_VAR(*pv2);

    const int *pv3 = new int(997);
    int *pv4 = const_cast<int *>(pv3);
    *pv4 = 998;
    SHOW_VAR(*pv3);
}