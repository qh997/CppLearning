#include <iostream>
using std::cout;
using std::endl;

#include "GradeBook.h"

int main()
{
    GradeBook myGradeBook1("CS101 Introduction to Programming in C++");
    GradeBook myGradeBook2("CS102 C++ Data structures");

    cout << "myGradeBook1 created for cpurse: "
         << myGradeBook1.getCourseName()
         << "\nmyGradeBook2 created for cpurse: "
         << myGradeBook2.getCourseName()
         << endl;

    myGradeBook1.setCourseName("CS101 C++ Programming");

    cout << "\nmyGradeBook1 created for cpurse: "
         << myGradeBook1.getCourseName()
         << "\nmyGradeBook2 created for cpurse: "
         << myGradeBook2.getCourseName()
         << endl;

    return 0;
}
