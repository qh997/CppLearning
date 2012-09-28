#include <iostream>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

#define SHOW_VAR(var) cout << #var" = " << var << endl

int main()
{
    SHOW_VAR(10 + 20);
    SHOW_VAR(10 - 5);
    SHOW_VAR(10 - 20);
    SHOW_VAR(10 * 20);
    SHOW_VAR(10 / 3);
    SHOW_VAR(10 % 3);
    SHOW_VAR(10 % -3);
    SHOW_VAR(-10 % 3);
    SHOW_VAR(-10 % -3);
    SHOW_VAR(10 + 20 / 10 - 5);
    SHOW_VAR((10 + 20) / (10 - 5));
    SHOW_VAR(10 + 20 / (10 - 5));
    SHOW_VAR((10 + 20) / 10 - 5);
    SHOW_VAR(4 * 5 / 3 % 4 + 7 / 3);

    cout << setw(5) << 10 + 20 << endl;
    cout << setw(5) << 10 - 5 << endl;
    cout << setw(5) << 10 - 20 << endl;
    cout << std::boolalpha << false << endl;

    unsigned int i = 55;
    SHOW_VAR(i);
    SHOW_VAR(-i);

    return EXIT_SUCCESS;
}