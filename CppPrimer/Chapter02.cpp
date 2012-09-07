#include <iostream>
#include <string>

std::string s1 = "hello";

class Foo
{
};

int main()
{
    int value(2); //直接初始化
    int power = 10; //复制初始化
    int result = 1;

    for (int cnt = 0; cnt < power; cnt++)
        result *= value;

    std::cout << value
             << " raised to the power of "
             << power << ": "
             << result << std::endl;

    std::string title("C++ Primer, 4th Ed.");
    std::string all_nine(10, '9');

    std::cout << title << std::endl;
    std::cout << all_nine << std::endl;

    std::string s2 = "world";
    std::cout << s1 << " " << s2 << std::endl;

    int s1 = 42;
    std::cout << s1 << " " << s2 << std::endl;

    int ival = 2;
    int &refVal = ival;
    int &refrefVal = refVal;
    refVal++;
    std::cout << "ival = " << ival << std::endl;
    refrefVal++;
    std::cout << "ival = " << ival << std::endl;

    const int bufsize = 5;
    const int &ref_bufsize = bufsize;
    std::cout << "ref_bufsize = " << ref_bufsize << std::endl;

    double dval = 3.14;
    const int &ri = dval;
    dval = 4.14;
    std::cout << "ri = " << ri << std::endl;
}