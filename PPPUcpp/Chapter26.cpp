#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template<class Iter, class T>
bool bin_search(Iter first, Iter last, const T &var)
{
    if (first == last)
        return false;

    if (var < *first || var > *(last - 1))
        return false;

    if (var == *first)
        return true;
    else if (var == *(last - 1))
        return true;

    Iter mid = first + (last - first) / 2;
    if (var == *mid)
        return true;
    else if(var < *mid)
        return bin_search(first, mid, var);
    else
        return bin_search(mid, last, var);
}

int main()
{
    int a[] = {1,2,3,5,8,13,21};

    int *end = a + sizeof(a)/sizeof(int);
    if (false == bin_search(a, end, 1)) cout << "1 failed" << endl;
    if (false == bin_search(a, end, 5)) cout << "2 failed" << endl;
    if (false == bin_search(a, end, 8)) cout << "3 failed" << endl;
    if (false == bin_search(a, end, 21)) cout << "5 failed" << endl;
    if (true == bin_search(a, end, -7)) cout << "8 failed" << endl;
    if (true == bin_search(a, end, 4)) cout << "13 failed" << endl;
    if (true == bin_search(a, end, 22)) cout << "21 failed" << endl;

    int n = 10000000;
    clock_t t1 = clock();
    if (t1 == clock_t(-1))
    {
        cerr << "error" << endl;
        return 1;
    }
    for (int i = 0; i < n; ++i)
        bin_search(a, end, 4);
    clock_t t2 = clock();
    if (t2 == clock_t(-1))
    {
        cerr << "error" << endl;
        return 1;
    }
    cout << n << " time took " << double(t2 - t1)/CLOCKS_PER_SEC << " seconds" << endl;
}
