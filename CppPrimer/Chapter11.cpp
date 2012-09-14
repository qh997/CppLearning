#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <list>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

bool isShorter(const string &s1, const string &s2);
bool GT6(const string &s);
void show_list(const list<int> &il);

int main()
{
    vector<string> sv;
    sv.push_back(string("lx"));
    sv.push_back(string("cxy"));
    sv.push_back(string("lj"));
    sv.push_back(string("xjj"));
    vector<string>::const_iterator result_sv = find(sv.begin(), sv.end(), "cxy");
    if (result_sv != sv.end())
        SHOW_VAR(*result_sv);

    int ia[] = {27, 210, 12, 47, 109, 83};
    int *result_ia = find(ia, ia + 6, 109);
    if (result_ia != ia + 6)
        SHOW_VAR(*result_ia);

    SHOW_VAR(accumulate(sv.begin(), sv.end(), string("")));

    vector<string> sv1;
    replace_copy(sv.begin(), sv.end(), back_inserter(sv1), string("lx"), string("lixue"));
    SHOW_VAR(sv1[0]);

    vector<string> words;
    words.push_back(string("the"));
    words.push_back(string("quick"));
    words.push_back(string("red"));
    words.push_back(string("fox"));
    words.push_back(string("jumps"));
    words.push_back(string("over"));
    words.push_back(string("the"));
    words.push_back(string("slow"));
    words.push_back(string("red"));
    words.push_back(string("turtle"));
    SHOW_VAR(words.size());
    sort(words.begin(), words.end());
    vector<string>::iterator end_unique
        = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    SHOW_VAR(words.size());
    stable_sort(words.begin(), words.end(), isShorter);
    vector<string>::size_type wc
        = count_if(words.begin(), words.end(), GT6);
    SHOW_VAR(wc);

    list<int> ilst, ilst2, ilst3;
    for (list<int>::size_type i = 0; i != 4; ++i)
        ilst.push_front(i);
    cout << "ilst:  "; show_list(ilst);
    copy(ilst.begin(), ilst.end(), front_inserter(ilst2));
    cout << "ilst2: "; show_list(ilst2);
    copy(ilst.begin(), ilst.end(), inserter(ilst3, ilst3.begin()));
    cout << "ilst3: "; show_list(ilst3);

    istream_iterator<string> in_iter(cin);
    istream_iterator<string> eof;
    ostream_iterator<string> out_iter(cout, "\n");
    vector<string> vec(in_iter, eof);
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
        *out_iter++ = "(OUT) " + *it;

    string line("cxy,lx,qq,xjj,lj,gs");
    string::iterator wbegn = line.begin();
    string::iterator comma = find(wbegn, line.end(), ',');
    while (true)
    {
        SHOW_VAR(string(wbegn, comma));
        if (comma == line.end())
            break;

        wbegn = comma;
        ++wbegn;
        comma = find(wbegn, line.end(), ',');
    }
    string::reverse_iterator rwbegn = line.rbegin();
    string::reverse_iterator rcomma = find(rwbegn, line.rend(), ',');
    while (true)
    {
        SHOW_VAR(string(rcomma.base(), rwbegn.base()));
        if (rcomma == line.rend())
            break;

        rwbegn = rcomma;
        ++rwbegn;
        rcomma = find(rwbegn, line.rend(), ',');
    }

    vector<string> vecl;
    reverse_copy(words.begin(), words.end(), back_inserter(vecl));

    return EXIT_SUCCESS;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool GT6(const string &s)
{
    return s.size() >= 4;
}

void show_list(const list<int> &il)
{
    for (list<int>::const_iterator it = il.begin(); it != il.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
