#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;

#define SHOW_VAR(var) cout << #var" = " << var << endl

int main()
{
    vector<int> vi(3, 997);

    vi.erase(vi.end() - 2);
    vi.insert(vi.end() - 1, 999);

    for (vector<int>::const_iterator i = vi.begin(); i != vi.end(); ++i)
        cout << *i << ' ';
    cout << endl;
}
