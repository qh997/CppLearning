template <class T>
vector<T>::vector()
    : sz(0), elem(0), space(0) {}

template <class T>
vector<T>::vector(int s)
    : sz(s), elem(new T[s])
{
    for (int i = 0; i < s; ++i)
        elem[i] = 0;
}

template <class T>
vector<T>::vector(const vector &arg)
    : sz(arg.sz), elem(new T[arg.sz])
{
    copy(arg);
}

template <class T>
vector<T> &vector<T>::operator=(const vector &a)
{
    if (this == &a)
        return *this;
    else if (a.sz <= space)
    {
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }
    else
    {
        T *p = new T(a.sz);
        for (int i = 0; i < a.sz; ++i)
            p[i] = a.elem[i];
        delete[] elem;
        space = sz = a.sz;
        elem = p;
        return *this;
    }
}

template <class T>
void vector<T>::resize(int newsize)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        elem[i] = 0;
    sz = newsize;
}

template <class T>
void vector<T>::push_back(T d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);

    elem[sz] = d;
    ++sz;
}

template <class T>
void vector<T>::reserve(int newalloc)
{
    if (newalloc <= space)
        return;

    T *p = new T[newalloc];
    for (int i = 0; i < sz; ++i)
        p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

template <class T>
void vector<T>::copy(const vector<T> &arg)
{
    for (int i = 0; i < arg.sz; ++i)
        elem[i] = arg.elem[i];
}
