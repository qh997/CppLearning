#include <iostream>
using std::cout;
using std::endl;

class GradeBook
{
public:
    void displayMessage()
    {
        cout << "Welcome to the Grade Boook!" << endl;
    }
};

int main()
{
    GradeBook myGradeBook;
    myGradeBook.displayMessage();
    return 0;
}
