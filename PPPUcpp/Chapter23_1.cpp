#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>

using namespace std;

typedef vector<string>::const_iterator Line_iter;

class Message
{
    Line_iter frist;
    Line_iter last;
  public:
    Message(Line_iter p1, Line_iter p2): frist(p1), last(p2) {}
    Line_iter begin() const {return frist;}
    Line_iter end() const {return last;}
};

typedef vector<Message>::const_iterator Mess_iter;

struct Mail_file
{
    string name;
    vector<string> lines;
    vector<Message> m;

    Mail_file(const string &n)
    {
        ifstream in(n.c_str());
        if(!in)
        {
            cerr << "no " << n << endl;
            exit(1);
        }

        string s;
        while (getline(in, s))
            lines.push_back(s);

        Line_iter frist = lines.begin();
        for (Line_iter p = lines.begin(); p != lines.end(); ++p)
        {
            if (*p == "----")
            {
                m.push_back(Message(frist, p));
                frist = p + 1;
            }
        }
    }

    Mess_iter begin() const {return m.begin();}
    Mess_iter end() const {return m.end();}
};

int is_prefix(const string &s, const string &p)
{
    int n = p.size();
    if (string(s, 0, n) == p)
        return n;

    return 0;
}

bool find_from_addr(const Message *m, string &s)
{
    for (Line_iter p = m->begin(); p != m->end(); ++p)
        if (int n = is_prefix(*p, "From: "))
        {
            s = string(*p, n);
            return true;
        }

    return false;
}

string find_subject(const Message *m)
{
    for (Line_iter p = m->begin(); p != m->end(); ++p)
        if (int n = is_prefix(*p, "Subject: "))
            return string(*p, n);
    return "";
}

int main()
{
    Mail_file mfile("my-mail-file.txt");

    multimap<string, const Message *> sender;

    for (Mess_iter p = mfile.begin(); p != mfile.end(); ++p)
    {
        const Message &m = *p;
        string s;
        if (find_from_addr(&m, s))
            sender.insert(make_pair(s, &m));
    }

    typedef multimap<string, const Message *>::const_iterator MCI;
    pair<MCI, MCI> pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for (MCI p = pp.first; p != pp.second; ++p)
    {
        cout << find_subject(p->second) << endl;
    }

    boost::regex pat("\\w");
}

/* Compile Command
g++ -o run Chapter23_1.cpp -lboost_regex
*/
