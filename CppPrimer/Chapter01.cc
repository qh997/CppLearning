#include <iostream>

int main()
{
    std::cout << "Hell C++ world!" << std::endl;

    int sum = 0, val = 1;

    while (val <= 10)
    {
        sum += val;
        val++;
    }
    std::cout << "Sum of 1 to 10 is " << sum << " (while)" << std::endl;

    sum = 0;
    for (int v = 1; v <= 10; v++)
        sum += v;
    std::cout << "Sum of 1 to 10 is " << sum << " (for)" << std::endl;

    return 0;
}