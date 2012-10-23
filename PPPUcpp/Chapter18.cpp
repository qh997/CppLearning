#include <iostream>
#include <stdexcept>
#include "vector.h"

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

struct X
{
    int val;

    void out(const string &s, int nv)
    {
        cerr << this << "->" << s << ": "
             << val << "(" << nv << ")" << endl;
    }

    X() {out("X()", 0); val = 0;}
    X(int v) {out("X(int)", v); val = v;}
    X(const X &x) {out("X(X&)", x.val); val = x.val;}
    X &operator=(const X &a)
        {out("X::operator=()", a.val); val = a.val; return *this;}
    ~X() {out("~X()", 0);}
};

bool is_palindrome(const string &s);

X glob(2);
X copy(X a) {return a;}
X copy2(X a) {X aa = a; return aa;}
X &ref_to(X &a) {return a;}
X *make(int i) {X a(i); return new X(a);}
struct XX {X a; X b;};

int main()
{
    vector<int> v(3);
    vector<int> v2 = v;

    v.set(1, 99);
    v2.set(0, 88);
    SHOW_VAR(v.get(0));
    SHOW_VAR(v2.get(1));

    v2 = v;
    SHOW_VAR(v2.get(1));
    v2[0] = 997;
    SHOW_VAR(v2[0]);

    int ia[20];
    SHOW_VAR(sizeof(ia));
    SHOW_VAR(sizeof(ia)/sizeof(int));

    SHOW_VAR(is_palindrome("asa"));

/*    X loc(4);
    X loc2 = loc;
    loc = X(5);
    loc2 = copy(loc);
    loc2 = copy2(loc);
    X loc3(6);
    X &r = ref_to(loc);
    delete make(7);
    delete make(8);
    //vector<X> v(4);
    XX loc4;
    X *p = new X(9);
    delete p;
    X *pp = new X[5];
    delete[] pp;*/
}

bool is_palindrome(const string &s)
{
    int frist = 0;
    int last = s.length() - 1;
    while (frist < last)
    {
        if (s[frist] != s[last])
            return false;
        ++frist;
        --last;
    }

    return true;
}
