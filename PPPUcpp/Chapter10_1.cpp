#include <iostream>
#include <stdexcept>

using namespace std;

void skip_to_int();

int main()
{
    cout << "Please enter an integer in the range 1 to 10(inclusive):" << endl;
    int n = 0;

    while (true)
    {
        cin >> n;
        if (cin)
        {
            if (1 <= n && n <= 10)
                break;

            cout << "Sorry " << n
                 << " is not in the [1:10] range; please try again"
                 << endl;
        }
        else if(cin.fail())
        {
            cout << "Sorry, that was not a number; please try again" << endl;
            skip_to_int();
        }
    }

    return 0;
}

void skip_to_int()
{
    if(cin.fail())
    {
        cin.clear();

        char ch;
        while (cin >> ch)
        {
            if (isdigit(ch))
            {
                cin.unget();
                return
            }
        }
    }

    throw runtime_error("no input");
}
