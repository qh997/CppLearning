#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <bitset>

using std::cout;
using std::string;
using std::vector;
using std::bitset;

int main()
{
    string s;
    s = "Hello C++ world!";
    cout << s << std::endl;

    string s1 = string("lx");
    cout << s1 << std::endl;

    cout << "s1.empty() = " << s1.empty() << std::endl;
    cout << "s.size() = " << s.size() << std::endl;
    for (string::size_type i = 0; i < s1.size(); ++i)
        cout << "s1[" << i << "] = " << s1[i] << std::endl;

    for (string::size_type i = 0; i < s.size(); ++i)
        cout << (char)toupper(s[i]);
    cout << std::endl;

    vector<int> ivec;
    cout << "ivec.size() = " << ivec.size() << std::endl;
    for (int i = 0; i != 10; ++i)
        ivec.push_back(i * i);
    cout << "ivec.size() = " << ivec.size() << std::endl;
    cout << "ivec[5] = " << ivec[5] << std::endl;

    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
        cout << "*iter = " << *iter << std::endl;

    vector<int>::iterator mid = ivec.begin() + ivec.size() / 2;
    cout << "*mid = " << *mid << std::endl;

    bitset<16> bitvec(0xffff);
    cout << "bitvec = " << bitvec << std::endl;

    string strval("1010110011100001011100");
    bitset<32> bitvec1(strval);
    cout << "bitvec1 = " << bitvec1 << std::endl;
}