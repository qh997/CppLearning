#include <string>
using std::string;

class GradeBook
{
public:
    GradeBook(string);
    void setCourseName(string);
    string getCourseName();
    void displayMessage();
    void inputGrades();
    void displayGradeReport();
    int maximun(int, int, int);

private:
    string courseName;
    int aCount;
    int bCount;
    int cCount;
    int dCount;
    int fCount;
    int maximumGrade;
};
