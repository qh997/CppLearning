#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

int main()
{
#ifndef NDEBUG // g++ -DNDEBUG -o run Chapter06.cpp
    std::cerr << "starting main\n"
              << "File : " << __FILE__ << "\n"
              << "Line : " << __LINE__ << "\n"
              << "Compile on : " << __DATE__ << " "
              << __TIME__ << "\n"
              << endl;
#endif

    assert(1 > 2);

    try
    {
        if (true)
        {
            throw runtime_error("Here is an error.");
        }
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
    }
}
