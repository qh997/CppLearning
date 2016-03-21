#include <iostream>
#include <string>
using namespace std;

class CreateAndDestroy {
public:
	CreateAndDestroy(int ID, string messageString) {
		objectID = ID;
		message = messageString;

		cout << "Object " << objectID << "  constructor runs   "
		     << message << endl;
	}

	~CreateAndDestroy() {
		cout << (objectID == 1 || objectID == 6 ? "\n" : "");
		cout << "Object " << objectID << "  destructor runs    "
		     << message << endl;
	}

private:
	int objectID;
	string message;
};

void create(void);

CreateAndDestroy frist(1, "(global before main)");

int main() {
	cout << "\nMAIN FUNCTION: EXECTUTION BEGINS" << endl;

	CreateAndDestroy second(2, "(local automatic in main)");
	static CreateAndDestroy third(3, "(local static in main)");

	create();
	cout << "\nMAIN FUNCTION: EXECTUTION RESUMES" << endl;
	
	CreateAndDestroy fourth(4, "(local automatic in main)");

	create();
	cout << "\nMAIN FUNCTION: EXECTUTION RESUMES" << endl;

	cout << "\nMAIN FUNCTION: EXECTUTION ENDS" << endl;
	return 0;
}

void create(void) {
	cout << "\nCREATE FUNCTION: EXECTUTION BEGINS" << endl;

	CreateAndDestroy fifth(5, "(local automatic in create)");
	static CreateAndDestroy sixth(6, "(local static in create)");
	CreateAndDestroy seventh(7, "(local automatic in create)");

	cout << "\nCREATE FUNCTION: EXECTUTION ENDS" << endl;
}
