#include <iostream>
#include <stdexcept>
#include <memory>
#include "vector.h"

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

template<class T, int N = 5>
struct array
{
    T elem[N];

    T &operator[](int n) {return elem[n];}
    const T &operator[](int n) const {return elem[n];}

    T *data() {return elem;}
    const T *data() const {return elem;}

    int size() const {return N;}
};

template<class C>
void printout(const C &c)
{
    for (int i = 0; i < c.size(); ++i)
        cout << c[i] << ' ';
    cout << endl;
}

struct No_default
{
    No_default(int) {}
};

vector<int> *make_vec()
{
    auto_ptr<vector<int> > p(new vector<int>);
    return p.release();
}

int main()
{
    vector<int> vi1;
    for (int i = 0; i != 8; ++i)
        vi1.push_back(i*i);
    SHOW_VAR(vi1[5]);
    printout(vi1);

    array<int, 5> ai5 = {0, 1, 2, 997, 3};
    SHOW_VAR(ai5[3]);
    printout(ai5);

    vector<int> v2(4, 23);
    printout(v2);
    v2.resize(6, 997);
    printout(v2);

    vector<int> *p = make_vec();
    p->push_back(997);
}
