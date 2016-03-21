#include <iostream>
#include <iomanip>

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << X << endl; \
} while(0)

#define SHOW_ARRAY(X) \
do { \
	cout << "Element of "#X"[]:" << endl; \
	for (int i = 0; i < sizeof(X)/sizeof(X[0]); i++) { \
		cout << setw(4) << X[i]; \
	} \
	cout << endl; \
} while(0)

enum e_order {
	ASC = 1,
	DES = 2,
};

typedef bool (*SORT_FUNC)(int, int);
typedef SORT_FUNC FUNC(e_order);
// typedef bool (*FUNC(e_order))(int, int);

void selectionSort(int * const work, const int size, SORT_FUNC func);
bool ascending(int a, int b);
bool desceding(int a, int b);
FUNC getFunc;

int main(int argc, char **argv) {
	const int arraySize = 10;
	e_order order = ASC;
	int counter = 0;
	int a[arraySize] = {4, 10, 18, 7, 39, 3, 5, 35, 41, 1};

	SHOW_ARRAY(a);

	switch (order) {
		case ASC:
			selectionSort(a, arraySize, ascending);
			break;

		case DES:
			selectionSort(a, arraySize, desceding);
			break;

		default:
			break;
	}

	SHOW_ARRAY(a);

	selectionSort(a, arraySize, desceding);
	SHOW_ARRAY(a);

	selectionSort(a, arraySize, getFunc(order));
	SHOW_ARRAY(a);
}

void selectionSort(int * const work, const int size, SORT_FUNC func) {
	for (int i = 1; i < size; i++) {
		int ele = work[i];
		int j = i - 1;
		while ((*func)(ele, work[j]) && 0 <= j) {
			work[j + 1] = work[j];
			work[j--] = ele;
		}
	}
}

bool ascending(int a, int b) {
	return a < b;
}

bool desceding(int a, int b) {
	return a > b;
}

SORT_FUNC getFunc(e_order o) {
	switch (o) {
		case ASC:
			return ascending;

		case DES:
			return desceding;

		default:
			return NULL;
	}
}
