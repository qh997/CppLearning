#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str1 = "a";
    string str2 = "b";
    string str3 = "c";
    string str4 = "d";
    string str5 = "e";

    vector<string *> strs;
    strs.push_back(&str1);
    strs.push_back(&str2);
    strs.push_back(&str3);
    strs.push_back(&str4);
    strs.push_back(&str5);

    for (vector<string *>::iterator iter = strs.begin(); iter != strs.end(); ++iter)
        cout << **iter << endl;

    int x[10];
    int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
    cout << sizeof(string) << endl;
    cout << sizeof(vector<string>) << endl;

    string *ps = new string("lx");
    cout << *ps << endl;
    delete ps;
    ps = NULL;

    vector<string> svec(10);
    cout << svec.size() << endl;

    vector<string> *pvec1 = new vector<string>(10);
    cout << (*pvec1).size() << endl;

    vector<string> *pv1 = &svec;

    vector<string> *pv2 = pvec1;
    //delete pvec1;
    delete pv2;
}