#include <iostream>
#include <iomanip>
#include "GradeBook.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

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

void GradeBook::displayMessage()
{
    cout << "Welcome to the grade boook for\n"
         << getCourseName() << '!' << endl;
}

void GradeBook::determineClassAverage()
{
    int total = 0;
    int gradeCounter = 0;
    int grade = 0;
    double average = 0.0;

    total = 0;
    gradeCounter = 0;

    do
    {
        cout << "Enter grade or -1 to quit: ";
        cin >> grade;

        if (!cin.fail())
        {
            if (-1 == grade)
                break;

            cout << "D: grade = " << grade << endl;
            total = total + grade;
            gradeCounter = gradeCounter + 1;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << endl;
        }

    } while (true);

    if (gradeCounter != 0)
    {
        average = static_cast<double>(total) / gradeCounter;

        cout << "\nTotal of all " << gradeCounter << " grades is "
             << total << endl;
        cout << "Class average is " << setprecision(2) << fixed
             << average << endl;
    }
    else
        cout << "No grades were entered" << endl;
}
