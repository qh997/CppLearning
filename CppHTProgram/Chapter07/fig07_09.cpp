#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

int main(int args, char **argv){
	const int arraySize = 11;
	int n[arraySize] = {
		0, 0, 0, 0, 0,
		1, 2, 5, 12, 8,
		3
	};

	cout << "Grade distribution:" << endl;

	for (int i = 0; i < arraySize; i++) {
		if (10 == i) {
			cout << setw(4) << "100: ";
		}
		else {
			cout << setw(4) << i * 10 << "-" << (i * 10 + 9) << ": ";
		}

		for (int j = 0; j < n[i]; j++) {
			cout << "*";
		}

		cout << endl;
	}

	return 0;
}
