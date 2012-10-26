#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;

class GradeBook
{
public:
    void setCourseName(string name)
    {
        courseName = name;
    }

    string getCoursename()
    {
        return courseName;
    }
    
    void displayMessage(string courseName)
    {
        cout << "Welcome to the grade boook for\n"
             << getCoursename() << '!' << endl;
    }

private:
    string courseName;
};

int main()
{
    string nameOfCourse;
    GradeBook myGradeBook;

    cout << "Initial course name is: "
         << myGradeBook.getCoursename() << endl;

    cout << "Please enter the course name:" << endl;
    getline(cin, nameOfCourse);
    myGradeBook.setCourseName(nameOfCourse);

    cout << endl;
    myGradeBook.displayMessage(nameOfCourse);
    return 0;
}
