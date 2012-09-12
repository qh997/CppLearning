#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int gcd(int v1, int v2);
void swap(int &v1, int &v2);
string::size_type find_char(const string &s, const char c);
void ptrswap(int *&v1, int *&v2);
void print_values(const int *beg, const int *end);
size_t count_calls();
const string &shorterString(const string &s1, const string &s2);

int i();

class Sales_item
{
  public:
    void set_isbn(const string &s)
    {isbn = s;}
    double avg_price() const;
    bool same_isbn(const Sales_item &rhs) const
    {return isbn == rhs.isbn;}
    Sales_item(): isbn("changxy"), units_sold(0), revenue(0.0) {}

  private:
    string isbn;
    unsigned units_sold;
    double revenue;
};

int main(int argc, char **argv)
{
    cout << gcd(99, 88) << endl;

    int v1 = 997, v2 = 256;
    swap(v1, v2);
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    const char *ptr = "hello";
    const char &rc = *ptr;

    cout << rc << endl;

    cout << find_char("changxy", 'c') << endl;

    int *pv1 = &v1, *pv2 = &v2;
    cout << "Before ptrswap(): "
         << "*pv1 = " << *pv1 << "; "
         << "*pv1 = " << *pv1 << endl;
    ptrswap(pv1, pv2);
    cout << "After  ptrswap(): "
         << "*pv1 = " << *pv1 << "; "
         << "*pv1 = " << *pv1 << endl;

    int ia[] = {1,2,3};
    print_values(ia, ia + 3);

    while (argc)
    {
        cout << *argv << endl;
        --argc;
        argv++;
    }

    count_calls();
    count_calls();
    count_calls();
    count_calls();
    cout << "count_calls() = " << count_calls() << endl;

    cout << "shorterString(\"lixue\", \"changxy\") = " << shorterString("lixue", "changxy") << endl;

    Sales_item s1;
    s1.set_isbn("lixue");
    Sales_item s2;
    s2.set_isbn("lixue");
    Sales_item *s3 = new Sales_item();

    cout << s1.same_isbn(s2) << endl;
    cout << s1.avg_price() << endl;
    cout << s3->same_isbn(s2) << endl;

    cout << "i = " << i << endl;
    cout << "i() = " << i() << endl;
    cout << "print_values = " << print_values << endl;

    void (*pv)(const int *, const int *);
    pv = &print_values;
    cout << "pv = " << pv << endl;
    pv(ia + 1, ia + 3);
}

int gcd(int v1, int v2)
{
    while (v2)
    {
        int tmp = v2;
        v2 = v1 % v2;
        v1 = tmp;
    }

    return v1;
}

void swap(int &v1, int &v2)
{
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
}

string::size_type find_char(const string &s, const char c)
{
    string::size_type i = 0;
    while (i != s.size() && s[i] != c)
        ++i;
    return i;
}

void ptrswap(int *&v1, int *&v2)
{
    int *tmp = v2;
    v2 = v1;
    v1 = tmp;
}

void print_values(const int *beg, const int *end)
{
    cout << __FUNCTION__ << endl;
    while (beg != end)
        cout << *beg++ << endl;
}

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() < s2.size() ? s1 : s2;
}

double Sales_item::avg_price() const
{
    return revenue;
}

int i()
{
    return 997;
}
