#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter your frist name and age(follow by 'enter'):\n";
    string frist_name = "lx";
    int age = 33;
    cout << "Hello," << frist_name << "!(age " << age <<")\n";

    cout << "Please enter a floating-point value:\n";
    double n = 9.97;
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nthree times n == " << 3*n
         << "\ntwice n == " << n+n
         << "\nn squared == " << n*n
         << "\nhalf of n == " << n/2
         << "\nsquare root of n == " << sqrt(n)
         << endl;

    string previous = "", current;
    
    int number_of_words = 0;
    while (cin >> current)
    {
        ++number_of_words;
        if (previous == current)
            cout << "word number " << number_of_words
                 << " repeated word:" << current << endl;
        previous = current;
    }

    int a = 20000;
    char c = a;
    if (a != c)
        cout << "opps!:" << a << "!=" << c << endl;

    return 0;
}