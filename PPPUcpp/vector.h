#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <memory>

struct out_of_range {};

template<class T, class A = std::allocator<T> >
class vector
{
    int sz;
    T *elem;
    int space;
    A alloc;

  public:
    typedef unsigned long size_type;
    typedef T value_type;
    typedef T *iterator;
    typedef const T *const_iterator;

    vector();
    explicit vector(int, T);
    vector(const vector &);
    ~vector() {delete[] elem;}

    vector &operator=(const vector &);
    T &operator[](int n) {return elem[n];}
    const T &operator[](int n) const {return elem[n];}
    T &at(int n);
    const T &at(int n) const;
    T &back() {return *(elem + sz - 1);}
    const T &back() const {return *(elem + sz - 1);}

    iterator begin() {return elem;}
    const_iterator begin() const {return elem;}
    iterator end() {return elem + sz;}
    const_iterator end() const {return elem + sz;}
    iterator insert(iterator p, const T &val);
    iterator erase(iterator p);

    size_type size() const {return sz;}
    int capacity() const {return space;}
    T get(int n) const {return elem[n];}
    void set(int n, T v) {elem[n] = v;}
    void resize(int, T);
    void push_back(const T &);

    void copy(const vector &);
    void reserve(int);
};

#include "vector.cpp"

#endif // __VECTOR_H__
