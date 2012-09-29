#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;

#define SHOW_VAR(var) cout << #var" = " << var << endl

void fill_vector(std::istream &is, vector<int> &vi, char terminator);

int main()
{
    vector<int> numbers;
    fill_vector(std::cin, numbers, '.');

    for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); ++i)
        SHOW_VAR(*i);

    return 0;
}

void fill_vector(std::istream &is, vector<int> &vi, char terminator)
{
    int i = 0;
    while (is >> i)
        vi.push_back(i);

    if (is.eof())
        return;
    
    is.clear();
    char c;
    is >> c;
    if (c != terminator)
    {
        is.unget();
        is.clear(std::ios_base::failbit);
    }
}