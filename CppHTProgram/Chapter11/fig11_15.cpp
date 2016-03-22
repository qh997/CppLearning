#include <iostream>
#include <string>

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

int main()
{
	string s1("happy");
	string s2(" ");
	string s3("birthday");
	string s4;

	SHOW(s1);
	SHOW(s1 + s2);
	SHOW(s4.empty());

	s4 = s1 + s2 + s3;
	SHOW(s4);
	SHOW(s4.substr(1, 6));

	s4[5] = 'X';
	SHOW(s4);

	for (string::iterator it = s4.begin(); it != s4.end(); ++it)
		SHOW(*it);

	for (string::reverse_iterator rit = s4.rbegin(); rit != s4.rend(); ++rit)
		SHOW(*rit);
}
