#include <string>

class GradeBook
{
public:
    GradeBook(std::string);
    void setCourseName(std::string);
    std::string getCourseName();
    void displayMessage();
    void determineClassAverage();
    void inputGrades();
    void displayGradeReport();

private:
    std::string courseName;
    int aCount;
    int bCount;
    int cCount;
    int dCount;
    int fCount;
};
