#include <iostream>
using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << X << endl; \
} while(0)

typedef int** iPP;

void foo(iPP const a) {
	int b = 997;
	SHOW(&b);
	*a = &b;
}

int main(int argc, char **argv) {
	int *countPtr, count = 5;

	countPtr = &count;

	SHOW(countPtr);
	SHOW(*countPtr);
	SHOW(&*countPtr);
	SHOW(*&countPtr);
	SHOW(*&*countPtr);

	foo(&countPtr);
	SHOW(countPtr);
	SHOW(*countPtr);

	return 0;
}
