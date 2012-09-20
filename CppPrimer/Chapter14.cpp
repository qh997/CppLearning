#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include "Sales_item.h"

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

class StrPtr;
class StringPtr;

class Foo
{
  public:
    int &operator[](const size_t index)
        {return data[index];}
    const int &operator[](const size_t index) const
        {return data[index];}

  //private:
    vector<int> data;
};

class StrPtr
{
    friend class StringPtr;

  private:
    string *sp;
    size_t use;
    StrPtr(string *p): sp(p), use(1) {}
    ~StrPtr() {delete sp;}
};

class StringPtr
{
  public:
    StringPtr(string *p): ptr(new StrPtr(p)) {}
    StringPtr(const StringPtr &orig): ptr(orig.ptr) {++ptr->use;}
    ~StringPtr() {if (--ptr->use == 0) delete ptr;}

    StringPtr &operator=(const StringPtr &s)
    {
        if (this != &s)
        {
            if (--ptr->use == 0)
                delete ptr;

            ptr = s.ptr;
        }

        return *this;
    }
    string &operator*() {return *ptr->sp;};
    string *operator->() {return ptr->sp;};
    const string &operator*() const {return *ptr->sp;};
    const string *operator->() const {return ptr->sp;};

  private:
    StrPtr *ptr;
};

class CheckedPtr
{
  public:
    CheckedPtr(int *b, int *e): be(b), en(e), cr(b) {}
    CheckedPtr operator++()
    {
        if (cr == en)
            throw out_of_range
                ("increment past the end of CheckedPtr");
        ++cr;
        return *this;
    }
    CheckedPtr operator--()
    {
        if (cr == be)
            throw out_of_range
                ("increment past the end of CheckedPtr");
        --cr;
        return *this;
    }
    CheckedPtr operator++(int)
    {
        CheckedPtr ret(*this);
        ++*this;
        return ret;
    }
    CheckedPtr operator--(int)
    {
        CheckedPtr ret(*this);
        --*this;
        return ret;
    }
    int var() const {return *cr;}

  private:
    int *be;
    int *en;
    int *cr;
};

class GT_cls
{
  public:
    GT_cls(size_t val = 0): bound(val) {}
    bool operator()(const string &s) const
        {return s.size() >= bound;}

  private:
    string::size_type bound;
};

int main()
{
    Sales_item si;
    cin >> si;
    cout << si << endl;

    Foo f1;
    f1.data.push_back(997);
    f1.data.push_back(998);
    f1.data.push_back(999);
    SHOW_VAR(f1[2]);

    StringPtr ip(new string("cxy"));
    SHOW_VAR(*ip);
    SHOW_VAR(ip.operator->()->length());
    StringPtr ip2(new string("lixue"));
    SHOW_VAR(*ip2);
    SHOW_VAR(ip2->length());
    ip2 = ip;
    SHOW_VAR(*ip2);
    SHOW_VAR(ip2->length());

    int ia[] = {1,2,3,4,5,6,7,8,9};
    CheckedPtr cp(ia, ia+9);
    SHOW_VAR((cp++).var());
    SHOW_VAR((++cp).var());

    vector<string> words;
    words.push_back("lixue");
    words.push_back("changxy");
    words.push_back("xuejj");
    words.push_back("qiuqing");
    words.push_back("wangying");
    SHOW_VAR(count_if(words.begin(), words.end(), GT_cls(6)));

    plus<int> intAdd;
    negate<int> intNegate;
    SHOW_VAR(intAdd(10, intNegate(20)));
    sort(words.begin(), words.end());
    cout << "words: ";
    for (vector<string>::const_iterator i = words.begin(); i != words.end(); ++i)
        cout << *i << " ";
    cout << endl;
    sort(words.begin(), words.end(), greater<string>());
    cout << "words: ";
    for (vector<string>::const_iterator i = words.begin(); i != words.end(); ++i)
        cout << *i << " ";
    cout << endl;

    vector<int> ivec;
    ivec.push_back(23);
    ivec.push_back(997);
    ivec.push_back(4);
    ivec.push_back(10);
    ivec.push_back(52);
    ivec.push_back(133);
    ivec.push_back(78);
    ivec.push_back(9);
    SHOW_VAR(count_if(ivec.begin(), ivec.end(), not1(bind2nd(less_equal<int>(), 10))));

    return EXIT_SUCCESS;
}