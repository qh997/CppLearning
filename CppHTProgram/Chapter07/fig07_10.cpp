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

int main()
{
    const int arraySize = 7;
    int frequency[arraySize] = {0};

    srand(time(NULL));

    for (int roll = 1; roll <= 6000000; ++roll)
        ++frequency[1 + rand() % 6];

    cout << "Face" << setw(13) << "Frequency" << endl;

    for (int face = 1; face < arraySize; ++face)
        cout << setw(2) << face << setw(14) << frequency[face]
             << endl;

    return 0;
}
