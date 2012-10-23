#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

template<class T>
string to_string(const T &t)
{
    ostringstream os;
    os << t;
    return os.str();
}

struct bad_from_string : bad_cast
{
    const char *what()
    {
        return "bad cast from string";
    }
};

template<class T>
T from_string(const string &s)
{
    istringstream is(s);
    T t;
    if (!(is >> t))
        throw bad_from_string();
    return t;
}

int main()
{
    string s1 = "Hello!";
    int i1 = 997;

    SHOW_VAR(to_string(s1));
    SHOW_VAR(to_string(i1));

    i1 = from_string<int>(to_string("229"));
    SHOW_VAR(i1);
}
