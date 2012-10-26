#include <iostream>
#include "GradeBook.h"

using std::cout;
using std::endl;
using std::string;

GradeBook::GradeBook(string name)
{
    setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
    if (name.length() <= 25)
        courseName = name;
    else
    {
        courseName = name.substr(0, 25);

        cout << "Name \"" << name
             << "\" exceeds maximum length (25).\n"
             << "Limiting courseName to first 25 characters.\n"
             << endl;
    }
}

string GradeBook::getCourseName()
{
    return courseName;
}

void GradeBook::displayMessage(string courseName)
{
    cout << "Welcome to the grade boook for\n"
         << getCourseName() << '!' << endl;
}
