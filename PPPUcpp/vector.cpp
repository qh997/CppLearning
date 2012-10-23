template<class T, class A>
vector<T, A>::vector()
    : sz(0), elem(0), space(0) {}

template<class T, class A>
vector<T, A>::vector(int s, T val = T())
    : sz(s), elem(new T[s])
{
    for (int i = 0; i < s; ++i)
        alloc.construct(&elem[i], val);
}

template<class T, class A>
vector<T, A>::vector(const vector &arg)
    : sz(arg.sz), elem(new T[arg.sz])
{
    copy(arg);
}

template<class T, class A>
vector<T, A> &vector<T, A>::operator=(const vector &a)
{
    if (this == &a)
        return *this;
    else if (a.sz <= space)
    {
        for (int i = 0; i < a.sz; ++i)
            alloc.construct(&elem[i], a.elem[i]);
        sz = a.sz;
        return *this;
    }
    else
    {
        T *p = alloc.allocate(a.sz);
        for (int i = 0; i < a.sz; ++i)
            alloc.construct(&p[i], a.elem[i]);
        for (int i = 0; i < sz; ++i)
            alloc.destroy(&elem[i]);
        alloc.deallocate(elem, space);
        space = sz = a.sz;
        elem = p;
        return *this;
    }
}

template<class T, class A>
T &vector<T, A>::at(int n)
{
    if (n < 0 || sz <= n)
        throw out_of_range();

    return elem[n];
}

template<class T, class A>
const T &vector<T, A>::at(int n) const
{
    if (n < 0 || sz <= n)
        throw out_of_range();

    return elem[n];
}

template<class T, class A>
typename vector<T, A>::iterator vector<T, A>::insert(iterator p, const T &val)
{
    int index = p - begin();
    if (size() == capacity())
        reserve(size() == 0 ? 8 : 2 * size());

    alloc.construct(elem + sz, back());
    ++sz;
    iterator pp = begin() + index;
    for (iterator pos = end() - 1; pos != pp; --pos)
        *pos = *(pos - 1);
    *(begin() + index) = val;
    return pp;
}

template<class T, class A>
typename vector<T, A>::iterator vector<T, A>::erase(iterator p)
{
    if (p == end())
        return p;

    alloc.destroy(&*p);
    for (iterator pos = p; pos != end(); ++pos)
        *(pos - 1) = *pos;

    alloc.destroy(&*(end() - 1));
    --sz;
    return p;
}

template<class T, class A>
void vector<T, A>::resize(int newsize, T val = T())
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        alloc.construct(&elem[i], val);
    sz = newsize;
}

template<class T, class A>
void vector<T, A>::push_back(const T &val)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);

    alloc.construct(&elem[sz], val);
    ++sz;
}

template<class T, class A>
void vector<T, A>::reserve(int newalloc)
{
    if (newalloc <= space)
        return;

    T *p = alloc.allocate(newalloc);
    for (int i = 0; i < sz; ++i)
        alloc.construct(&p[i], elem[i]);
    for (int i = 0; i < sz; ++i)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);
    elem = p;
    space = newalloc;
}

template<class T, class A>
void vector<T, A>::copy(const vector &arg)
{
    for (int i = 0; i < arg.sz; ++i)
        alloc.construct(&elem[i], arg.elem[i]);
}
