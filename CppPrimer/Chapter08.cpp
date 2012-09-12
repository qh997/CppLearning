#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

int main()
{
    int ival;

    while (cin >> ival, !cin.eof())
    {
        if (cin.bad())
            throw runtime_error("IO stream corrupted.");

        if (cin.fail())
        {
            cerr << "bad data, try again." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        cout << "input : " << ival << endl;
    }
}