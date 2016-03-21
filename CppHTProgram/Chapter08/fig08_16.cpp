#include <iostream>
using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << X << endl; \
} while(0)

template<class T>
size_t getSize(T *ptr) {
	return sizeof(ptr);
}

void foo(int * const a) { //不能改变a所指的单元
	*a = 9;
}

void bar(const int *a) { //不能改变a所指单元的内容
	int b = 997;
	a = &b;
}

int main(void) {
	double array[20];
	int arrayI[200];
	int *a = arrayI + 8;

	SHOW(sizeof(array));
	SHOW(sizeof(array)/sizeof(double));
	SHOW(getSize(array));
	SHOW(getSize(arrayI));

	foo(a);
	SHOW(a);
	SHOW(*a);

	bar(a);
	SHOW(a);
	SHOW(*a);

	return 0;
}
