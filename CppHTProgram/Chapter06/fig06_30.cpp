#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

unsigned long fibonacci(unsigned long);

int main()
{
    for (int counter = 0; counter <= 10; ++counter)
        cout << "fibonacci(" << setw(2) << counter << ") = "
             << fibonacci(counter) << endl;

    cout << "fibonacci(20) = " << fibonacci(20) << endl;
    cout << "fibonacci(30) = " << fibonacci(30) << endl;
    cout << "fibonacci(35) = " << fibonacci(35) << endl;

    return 0;
}

unsigned long fibonacci(unsigned long number)
{
    if ((0 == number) || (1 == number))
        return number;
    else 
        return fibonacci(number - 2) + fibonacci(number - 1);
}
