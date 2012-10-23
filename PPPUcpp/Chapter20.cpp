#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
//#include "vector.h"
//#include "list.h"

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

typedef vector<char> Line;

class Text_iterator
{
    list<Line>::iterator ln;
    Line::iterator pos;
  public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        : ln(ll), pos(pp) {}

    char &operator*() {return *pos;}
    Text_iterator &operator++()
    {
        ++pos;

        if (pos == (*ln).end())
        {
            ++ln;
            pos = (*ln).begin();
        }

        return *this;
    }

    bool operator==(const Text_iterator &other) const
    {
        return ln == other.ln && pos == other.pos;
    }
    bool operator!=(const Text_iterator &other) const
    {
        return !(*this == other);
    }
};

struct Document
{
    list<Line> line;

    Document() {line.push_back(Line());}

    Text_iterator begin()
    {
        return Text_iterator(line.begin(), (*line.begin()).begin());
    }
    Text_iterator end()
    {
        list<Line>::iterator last = line.end();
        --last;
        return Text_iterator(last, (*last).end());
    }
};

istream &operator>>(istream &is, Document &d)
{
    char ch;
    while (is.get(ch))
    {
        d.line.back().push_back(ch);
        if (ch == '\n')
            d.line.push_back(Line());
    }
    return is;
}

void print(Document &d)
{
    cout << "Document :\n";

    for (Text_iterator p = d.begin(); p != d.end(); ++p)
        cout << *p;
    
    cout << "Document end." << endl;
}

template<class Iter>
Iter advance(Iter p, int n)
{
    while (n > 0)
    {
        ++p;
        --n;
    }

    return p;
}

void erase_line(Document &d, int n)
{
    if (n < 0 || d.line.size() <= n)
        return;

    d.line.erase(advance(d.line.begin(), n));
}

template<class Iter>
bool match(Iter p, Iter l, const string &s)
{
    int si = 0;
    for (Iter i = p; i != l; ++i, ++si)
    {
        if (si >= s.size())
            return false;

        if (*p != s[si])
            return false;
    }

    return true;
}

/*Text_iterator find_txt(Text_iterator frist, Text_iterator last, const string &s)
{
    if (s.size() == 0)
        return last;
    char frist_char = s[0];
    while (true)
    {
        Text_iterator p = find(frist, last, frist_char);
        if (p == last || match(p, last, s))
            return p;
    }
}*/

int main()
{
    Document my_doc;
    cin >> my_doc;

    print(my_doc);

    vector<int> vi(5, 997);

    find(my_doc.begin(), my_doc.end(), 'a');
}
