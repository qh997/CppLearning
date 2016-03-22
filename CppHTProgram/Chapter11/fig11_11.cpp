#include <iostream>
#include "String.h"

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

int main()
{
	String str1("0123456789");
	String str2("happy");
	String str3("birthday");
	SHOW(str1);
	SHOW(str1(3, -20));
	SHOW(str1(3, 20));
	SHOW(str1(3, 5));
	SHOW(str1(3, -2));
	SHOW(str1(-3, -5));
	SHOW(str1(-3, 20));
	SHOW(str1(20, 20));
	SHOW(str1(20, -17));
	SHOW(str1(20, -170));

	SHOW(str2 == str3);
	SHOW(str2 != str3);
	SHOW(str2 > str3);
	SHOW(str2 >= str3);
	SHOW(str2 < str3);
	SHOW(str2 <= str3);

	SHOW((str1 = "").getLength());

	str2 += " ";
	SHOW(str2);
	str2 += str3;
	SHOW(str2);

	String str4(str2);
	SHOW(str4);

	str1 = str3;
	SHOW(str1);
	SHOW(str1.getLength());
}
