#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

int main()
{
    unsigned seed;

    cout << "Enter seed: ";
    cin >> seed;
    srand(seed);

    for (int counter = 1; counter <= 10; ++counter)
    {
        cout << setw(10) << (1 + rand() % 6);

        if (counter % 5 == 0)
            cout << endl;
    }

    return 0;
}
