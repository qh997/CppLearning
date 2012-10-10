#include "vector.h"

vector::vector(int s)
    : sz(s), elem(new double[s])
{
    for (int i = 0; i < s; ++i)
        elem[i] = 0;
}

void vector::copy(const vector &arg)
{
    for (int i = 0; i < arg.sz; ++i)
        elem[i] = arg.elem[i];
}

vector::vector(const vector &arg)
    : sz(arg.sz), elem(new double[arg.sz])
{
    copy(arg);
}

vector &vector::operator=(const vector &a)
{
    double *p = new double(a.sz);
    for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}
