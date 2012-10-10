#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

#include "punct_stream.h"

using namespace std;

ios_base& general(ios_base &b);
template<class T>
void str_to_class(string s, T &o);

int main()
{
    cout << dec << 1234 << "\t(decimal)\n"
         << hex << 1234 << "\t(hexadecimal)\n"
         << oct << 1234 << "\t(octal)\n"
         << endl;

    cout << dec << 1234 << "\t" << hex << 1234 << "\t" << oct << 1234 << endl;
    cout << showbase;
    cout << dec << 1234 << "\t" << hex << 1234 << "\t" << oct << 1234 << endl;
    cout << dec;
    cout << endl;

    cout << 1234.56789 << "\t\t(general)\n"
         << fixed << 1234.56789 << "\t(fixed)\n"
         << scientific << 1234.56789 << "\t(scientific)\n"
         << endl;
    cout << general;

    cout << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << 1234.56789 << '\n';
    cout << general << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n'
         << endl;
    cout << general;

    cout << 123456
         << '|' << setw(4) << 123456 << '|'
         << setw(8) << 123456 << '|'
         << 123456 << "|\n"
         << endl;

    double d1;
    str_to_class(string("3.14159"), d1);
    cout << "d1 = " << d1 << endl;

    char c1;
    str_to_class(string("X"), c1);
    cout << "c1 = " << c1 << endl;

    Punct_stream ps(cin);
    ps.whitespace("~!@#$%^&*()_+-=[]\\{}|;':\",./<>?");
    ps.case_sensitive(false);
    vector<string> vs;
    string word;
    while (ps >> word)
        vs.push_back(word);
    sort (vs.begin(), vs.end());
    for (vector<string>::const_iterator i = vs.begin(); i != vs.end(); ++i)
        cout << *i << endl;
}

inline ios_base& general(ios_base &b)
{
    b.setf(ios_base::fmtflags(0), ios_base::floatfield);
    return b;
}

template<class T>
void str_to_class(string s, T &o)
{
    istringstream is(s);
    is >> o;
    if (!is)
        throw runtime_error("double format error: " + s);
}
