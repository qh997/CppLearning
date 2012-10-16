#ifndef __VECTOR_H__
#define __VECTOR_H__

template <class T>
class vector
{
  public:
    vector();
    explicit vector(int);
    vector(const vector &);
    ~vector() {delete[] elem;}

    vector &operator=(const vector &);
    T &operator[](int n) {return elem[n];}
    const T &operator[](int n) const {return elem[n];}

    int size() const {return sz;}
    int capacity() const {return space;}
    T get(int n) const {return elem[n];}
    void set(int n, T v) {elem[n] = v;}
    void resize(int);
    void push_back(T);
    void reserve(int);

  private:
    void copy(const vector &);

    int sz;
    T *elem;
    int space;
};

#include "vector.cpp"

#endif // __VECTOR_H__
