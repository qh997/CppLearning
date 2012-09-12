#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

class Sales_item {};

int main()
{
    vector<string> svec;
    list<int> ilist;
    deque<Sales_item> items;

    list<string> slist(svec.begin(), svec.end());

    const char *words[] = {"stately", "plump", "duck", "mulligan"};
    list<string> words2(words, words + sizeof(words)/sizeof(char *));
    cout << "words2.size() = " << words2.size() << endl;

    for (list<string>::iterator iter = words2.begin(); iter != words2.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    for (list<string>::reverse_iterator iter = words2.rbegin(); iter != words2.rend(); ++iter)
        cout << *iter << " ";
    cout << endl;

    vector< vector<string> > iv(5);
    cout << "iv.size() = " << iv.size() << endl;
    cout << "iv[0].size() = " << iv[0].size() << endl;

    list<string> names;
    names.push_back("changxy");
    names.push_front("lixue");
    names.insert(names.end(), "xuejj");
    for (list<string>::iterator iter = names.begin(); iter != names.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    vector<int> v(7, 997);
    deque<int> eve, odd, *tmp = &eve;
    if (v.size() % 2)
        tmp = &odd;

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        tmp->push_back(*iter);
    cout << "eve: ";
    for (deque<int>::iterator iter = eve.begin(); iter != eve.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "odd: ";
    for (deque<int>::iterator iter = odd.begin(); iter != odd.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "odd.max_size() = " << odd.max_size() << endl;
    cout << "odd.size() = " << odd.size() << endl;
    odd.resize(100, 0);
    cout << "odd.size() = " << odd.size() << endl;
    odd.resize(10);
    cout << "odd.size() = " << odd.size() << endl;

    cout << "odd: ";
    for (deque<int>::iterator iter = odd.begin(); iter != odd.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "odd[5] == odd.at(5) : " << odd[5] << " == " << odd.at(5) << endl;

    odd.erase(odd.begin() + 4);
    odd.erase(odd.end() - 2);
    cout << "odd: ";
    for (deque<int>::iterator iter = odd.begin(); iter != odd.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    odd.clear();
    odd.clear();
    cout << "odd: ";
    for (deque<int>::iterator iter = odd.begin(); iter != odd.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    vector<int> c1, c2;
    for (int i = 0; i != 10; ++i)
        c1.push_back(i * i);
    for (int i = 0; i != 7; ++i)
        c2.push_back(i * 3);
    cout << "c1: ";
    for (vector<int>::iterator iter = c1.begin(); iter != c1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "c2: ";
    for (vector<int>::iterator iter = c2.begin(); iter != c2.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    c1 = c2;
    c1[5] = 997;
    cout << "c1: ";
    for (vector<int>::iterator iter = c1.begin(); iter != c1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    c2.assign(2, 888);
    cout << "c2: ";
    for (vector<int>::iterator iter = c2.begin(); iter != c2.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    list<const char *> clist;
    clist.push_back("Aa");
    clist.push_back("Bb");
    clist.push_back("Cc");
    clist.push_back("Dd");
    clist.push_back("Ee");
    cout << "clist: ";
    for (list<const char *>::iterator iter = clist.begin(); iter != clist.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    vector<string> svect;
    svect.assign(clist.begin(), clist.end());
    svect[3] = "Hh";
    svect.push_back("Xx");
    cout << "svect: ";
    for (vector<string>::iterator iter = svect.begin(); iter != svect.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "svect.size() = " << svect.size() << endl;
    cout << "svect.capacity() = " << svect.capacity() << endl;
    svect.reserve(50);
    cout << "svect.capacity() = " << svect.capacity() << endl;

    stack< string, vector<string> > str_stk(svect);

    const stack<int>::size_type stk_size = 10;
    stack<int> intStack;
    int ix = 0;
    while (intStack.size() != stk_size)
        intStack.push(ix++);
    int error_cnt = 0;
    while (intStack.empty() == false)
    {
        int value = intStack.top();

        if (value != --ix)
        {
            cerr << "OOPS!" << endl;
            ++error_cnt;
        }
        intStack.pop();
    }

    return EXIT_SUCCESS;
}
