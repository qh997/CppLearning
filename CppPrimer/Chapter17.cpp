#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

namespace my_names
{
    class Person {};

    int i;

    namespace
    {
        string s("lx");
    }
}

int main(int argc, char const **argv)
{
    int i = 7;
    my_names::i = 5;
    SHOW_VAR(i);
    SHOW_VAR(my_names::i);
    SHOW_VAR(my_names::s);

    return EXIT_SUCCESS;
}