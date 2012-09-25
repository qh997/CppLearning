#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <cstring>
#include "Chapter16_1.h"

#define SHOW_VAR(var) cout << #var" = " << var << endl

using namespace std;

template <typename T, size_t N>
size_t array_size(const T (&parm)[N])
{
    return N;
}

template <class T1, class T2, class T3>
T1 sum(T2 v1, T3 v2)
{
    return v1 + v2;
}

template <class T>
class Foo
{
  public:
    static size_t count() {return ++ctr;}
  private:
    static size_t ctr;
};

template <class T> size_t Foo<T>::ctr = 5;

template <class T>
class Handle
{
  public:
    Handle(T *p = 0): ptr(p), use(new size_t(1)) {}
    Handle(const Handle &h): ptr(h.ptr), use(h.use) {++*use;}
    ~Handle() {rem_ref();}

    T &operator*();
    T *operator->();
    const T &operator*() const;
    const T *operator->() const;
    Handle & operator=(const Handle &);


  private:
    T *ptr;
    size_t *use;
    void rem_ref()
    {
        if (--*use == 0)
        {
            delete ptr;
            delete use;
        }
    }
};

template <class T>
inline Handle<T> &Handle<T>::operator=(const Handle &rhs)
{
    ++*rhs.use;
    rem_ref();
    ptr = rhs.ptr;
    use = rhs.use;

    return *this;
}

template <class T>
inline T &Handle<T>::operator*()
{
    if (ptr)
        return *ptr;

    throw std::runtime_error("dereference of unbound Handle");
}

template <class T>
inline T *Handle<T>::operator->()
{
    if (ptr)
        return ptr;

    throw std::runtime_error("dereference of unbound Handle");
}

template <class T>
inline const T &Handle<T>::operator*() const
{
    if (ptr)
        return *ptr;

    throw std::runtime_error("dereference of unbound Handle");
}

template <class T>
inline const T *Handle<T>::operator->() const
{
    if (ptr)
        return ptr;

    throw std::runtime_error("dereference of unbound Handle");
}

template <>
int compare<const char *>(const char *const &v1,
                          const char *const &v2)
{
    return strcmp(v1, v2);
}

int main()
{
    SHOW_VAR(compare(1, 3));
    SHOW_VAR(compare<string>("lx", "gengs"));
    SHOW_VAR(compare<double>(5, 5.0));
    int a[23];
    SHOW_VAR(array_size(a));
    long v3 = sum<long>(81190, 2);
    SHOW_VAR(v3);

    Queue<string> qs;
    qs.push("changxy");
    qs.push("lixue");
    qs.push("xuejj");
    cout << qs << endl;

    Queue<int> qi;
    short ai[] = {2,3,4,5,6,7,8};
    qi.assign(ai, ai + 7);
    cout << qi << endl;

    SHOW_VAR(Foo<int>::count());
    SHOW_VAR(Foo<int>::count());
    SHOW_VAR(Foo<int>::count());
    SHOW_VAR(Foo<double>::count());

    Handle<int> hp(new int(42));
    {
        Handle<int> hp2 = hp;
        cout << *hp << " " << *hp2 << endl;
        *hp2 = 10;
    }
    cout << *hp << endl;

    const char *cp1 = "lx", *cp2 = "gs";
    SHOW_VAR(compare(cp1, cp2));

    Queue<const char *> sq;
    sq.push(cp1);
    sq.push(cp2);
    SHOW_VAR(sq.front());

    return EXIT_SUCCESS;
}
