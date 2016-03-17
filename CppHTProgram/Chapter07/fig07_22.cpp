#include <iostream>
using namespace std;

int main(int argn, char **argv) {
	int array[2][3] = {{1,2,3}, {4,5,6}};
	void *a = NULL;

	a = array;

	for (int i = 0; i < 2 * 3; i++) {
		cout << *static_cast<int *>(a) << endl;
		a = static_cast<int *>(a) + 1;
	}

	return 0;
}
