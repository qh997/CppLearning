#include <iostream>
#include <cstdlib>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

class Person
{
  public:
    Person();
    Person(const Person &person);
    Person(const string &fn, const string &ln);
    Person &operator=(const Person &person);
    ~Person();

    string frist_name;
    string *last_name;
};

Person::Person()
    : last_name(new string())
{}

Person::Person(const Person &person)
    : frist_name(person.frist_name),
      last_name(new string(*(person.last_name)))
{}

Person::Person(const string &fn, const string &ln)
    : frist_name(fn), last_name(new string(ln))
{}

Person &Person::operator=(const Person &person)
{
    frist_name = person.frist_name;
    last_name = person.last_name;

    return *this;
}

Person::~Person()
{
    cout << frist_name << " "
         << *last_name << " "
         << "Destroy..." << endl;
}

class HasPtr
{
  public:
    HasPtr(const int &p, int i)
        : ptr(new int(p)), val(i) {}
    HasPtr(const HasPtr &orig)
        : ptr(new int(*orig.ptr)), val(orig.val) {}
    HasPtr &operator=(const HasPtr &rhs)
    {
        *ptr = *rhs.ptr;
        val = rhs.val;
        return *this;
    }
    ~HasPtr() {delete ptr;}

    int get_ptr_val() const {return *ptr;}
    int get_int() const {return val;}
    void set_ptr(int *p) {ptr = p;}
    void set_int(int i) {val = i;}
    int *get_ptr() const {return ptr;}
    void set_ptr_val(int i) const {*ptr = i;}

  private:
    int *ptr;
    int val;
};

int main()
{
    Person p1("li", "xue");
    Person p2(p1);
    *(p2.last_name) = "jia";
    SHOW_VAR(p1.frist_name);
    SHOW_VAR(*(p1.last_name));
    SHOW_VAR(p2.frist_name);
    SHOW_VAR(*(p2.last_name));
    Person p3;
    p3 = p2;
    *(p3.last_name) = "X";
    SHOW_VAR(p2.frist_name);
    SHOW_VAR(*(p2.last_name));
    SHOW_VAR(p3.frist_name);
    SHOW_VAR(*(p3.last_name));

    return EXIT_SUCCESS;
}
