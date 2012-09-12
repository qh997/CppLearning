#include <iostream>
#include <cstdlib>
#include <map>

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

    return EXIT_SUCCESS;
}