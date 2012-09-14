#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

int main()
{
    map<string, int> xcount;
    ++xcount["lx"];
    SHOW_VAR(xcount["lx"]);
    SHOW_VAR(xcount["cxy"]);
    SHOW_VAR(xcount.size());

    xcount.insert(map<string, int>::value_type("xjj", 2));
    SHOW_VAR(xcount["xjj"]);
    SHOW_VAR(xcount.size());

    pair<map<string, int>::iterator, bool> ret = xcount.insert(make_pair("lj", 3));
    SHOW_VAR(ret.second);
    SHOW_VAR(xcount.size());
    SHOW_VAR(xcount["lj"]);

    ret = xcount.insert(make_pair("lj", 3));
    if (!ret.second)
        ret.first->second += 3;
    SHOW_VAR(ret.second);
    SHOW_VAR(xcount.size());
    SHOW_VAR(xcount[ret.first->first]);

    if (xcount.count("gs"))
        SHOW_VAR(xcount["gs"]);
    SHOW_VAR(xcount.size());

    map<string, int>::iterator it = xcount.find("lx");
    if (xcount.end() != it)
        SHOW_VAR(it->second);

    
    for (map<string, int>::iterator map_it = xcount.begin(); map_it != xcount.end(); ++map_it)
    {
        SHOW_VAR(map_it->first);
        SHOW_VAR(map_it->second);
    }

    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.begin(), ivec.end());
    SHOW_VAR(ivec.size());
    SHOW_VAR(iset.size());
    SHOW_VAR(iset.count(8));
    SHOW_VAR(iset.count(12));

    multimap<string, string> xuw;
    xuw.insert(make_pair(string("lx"), string("red")));
    xuw.insert(make_pair(string("lx"), string("black")));
    xuw.insert(make_pair(string("lx"), string("purple")));
    xuw.insert(make_pair(string("lx"), string("flesh")));

    multimap<string, string>::iterator xuw_i = xuw.find("lx");
    for (multimap<string, string>::size_type i = 0; i != xuw.count("lx"); ++i, ++xuw_i)
        SHOW_VAR(xuw_i->second);

    for (multimap<string, string>::iterator beg = xuw.lower_bound("lx"), end = xuw.upper_bound("lx"); beg!= end; ++beg)
        SHOW_VAR(beg->second);

    return EXIT_SUCCESS;
}