#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>
using std::time;

#define print(X) \
do { \
    cout << setw(16) << #X" = "<< sizeof(X) << endl; \
} while(0)

void foo(int a) {
    return;
}

void foo(float a) {
    return;
}

int main()
{
    const int arraySize = 6;
    int frequency[arraySize] = {0};

    srand(time(NULL));

    for (int roll = 0; roll < 6000000; ++roll)
        ++frequency[rand() % 6];

    cout << "Face" << setw(13) << "Frequency" << endl;

    for (int face = 0; face < arraySize; ++face)
        cout << setw(2) << face + 1 << setw(14) << frequency[face]
             << endl;

    print(char);
    print(short);
    print(int);
    print(long);
    print(long long);
    print(float);
    print(double);
    print(void *);

    int *p = new int[20];
    print(p);
    print(*p);
    delete []p;

    return 0;
}
