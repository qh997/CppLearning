#include <iostream>
#include <cstdlib>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

int main(int argc, char **argv)
{
    SHOW_VAR(*argv);

    return EXIT_SUCCESS;
}