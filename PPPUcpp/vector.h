#ifndef __VECTOR_H__
#define __VECTOR_H__

class vector
{
    int sz;
    double *elem;
    void copy(const vector &);

  public:
    explicit vector(int);
    vector(const vector &);
    ~vector() {delete[] elem;}
    vector &operator=(const vector &);
    double &operator[](int n) {return elem[n];}
    const double &operator[](int n) const {return elem[n];}

    int size() const {return sz;}
    double get(int n) const {return elem[n];}
    void set(int n, double v) {elem[n] = v;}
};

#endif // __VECTOR_H__
