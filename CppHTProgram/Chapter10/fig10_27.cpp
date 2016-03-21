#include <iostream>
using namespace std;

// 使用代理类隐藏类的细节

#include "Interface.h"

int main()
{
	Interface i(5);

	cout << i.getValue() << endl;

	i.setValue(10);

	cout << i.getValue() << endl;

	return 0;
}
