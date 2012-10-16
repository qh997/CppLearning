#include <iostream>
#include <stdexcept>
#include "vector.h"
#include "Simple_window.h"

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

int main()
{
    vector<int> vi1;
    for (int i = 0; i != 8; ++i)
        vi1.push_back(i*i);

    SHOW_VAR(vi1[5]);
}
