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
    GradeBook(string name)
    {
        setCourseName(name);
    }

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
    GradeBook myGradeBook1("CS101 Introduction to C++ Programming");
    GradeBook myGradeBook2("CS102 Data structures in C++");

    cout << "myGradeBook1 created for cpurse: "
         << myGradeBook1.getCoursename()
         << "\nmyGradeBook2 created for cpurse: "
         << myGradeBook2.getCoursename()
         << endl;

    return 0;
}
