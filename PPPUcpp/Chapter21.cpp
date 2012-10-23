#include <iostream>
#include <map>
#include "vector.h"

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

template<class In, class T>
In find(In frist, In last, const T &val)
{
    while (frist != last && *frist != val)
        ++frist;

    return frist;
}

template<class In, class Pred>
In find_if(In frist, In last, Pred pred)
{
    while (frist != last && !pred(*frist))
        ++frist;

    return frist;
}

class Langer_than
{
    int v;
  public:
    Langer_than(int vv): v(vv) {}
    bool operator()(int x) const {return x > v;}
};

template<class In, class T>
T accumulate(In frist, In last, T init)
{
    while (frist != last)
        init += *(frist++);

    return init;
}

template<class In, class T, class BinOp>
T accumulate(In frist, In last, T init, BinOp op)
{
    while (frist != last)
        init = op(init, *(frist++));

    return init;
}

template<class T>
struct OPOM
{
    OPOM(int p = true): plus(!p) {}
    T operator()(T t1, T t2)
    {
        plus = !plus;
        if (plus)
            return t1 + t2;
        else
            return t1 - t2;
    }

    bool plus;
};

int main()
{
    vector<int> vi;
    vi.push_back(23);
    vi.push_back(44);
    vi.push_back(3);
    vi.push_back(97);
    vi.push_back(50);

    SHOW_VAR(*(find_if(vi.begin(), vi.end(), Langer_than(45))));
    SHOW_VAR(accumulate(vi.begin(), vi.end(), int(0)));
    SHOW_VAR(accumulate(vi.begin(), vi.end(), int(0), OPOM<int>(false)));
}
