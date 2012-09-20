#include <iostream>
#include <cstdlib>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

class Person
{
    friend class PersonMgr;

  public:
    typedef char cup_type;
    Person(const string &fname, const string &lname);
    string full_name() const;
    string full_name(bool i18n) const;
    Person &set_cup(const cup_type c);
    Person &set_color(const string &clr);
    void show() const;

  private:
    string frist_name;
    string last_name;
    cup_type cup;
    string color;
    mutable int times;
    static string owner;
    static void say_hi();
};

Person::Person(const string &fname = "qiu", const string &lname = "qing")
    : frist_name(fname), last_name(lname), cup('B'), times(0)
{}

inline string Person::full_name() const
{
    return frist_name + " " + last_name;
}

string Person::full_name(bool i18n) const
{
    if (i18n)
        return last_name + " " + frist_name;
    else
        return full_name();
}

Person &Person::set_cup(const cup_type c)
{
    cup = c;

    return *this;
}

inline void Person::show() const
{
    cout << "Hi, I am " << full_name()
         << ", and I have " << cup
         << " cup.(" << ++times << ")" << endl;
    say_hi();
}

string Person::owner("gengs");

void Person::say_hi()
{
    cout << "Hi " << owner
         << " I am ready for you." << endl;
}

class PersonMgr
{
  public:
    void chang_cup(Person &p, const char c)
        {p.cup = c;};
};

int main()
{
    Person s1("li", "xue");
    SHOW_VAR(s1.full_name());
    SHOW_VAR(s1.full_name(true));
    s1.set_cup('D').show();

    const Person s2("xue", "jiajia");
    s2.show();

    Person s3;
    s3.show();

    PersonMgr gs;
    gs.chang_cup(s3, 'D');
    s3.show();

    return EXIT_SUCCESS;
}
