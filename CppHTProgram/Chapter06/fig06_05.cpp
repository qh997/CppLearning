#include "GradeBook.h"

int main()
{
    GradeBook myGradebook("CS101 C++ Programming");

    myGradebook.displayMessage();
    myGradebook.inputGrades();
    myGradebook.displayGradeReport();
    return 0;
}
