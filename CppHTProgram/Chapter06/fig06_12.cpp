#include <iostream>
using std::cout;
using std::endl;

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x = 1;

int main()
{
    int x = 5;

    cout << "local x in main's outer scope is " << x << endl;

    {
        int x = 7;

        cout << "local x in main's inner scope is " << x << endl;
    }

    cout << "local x in main's outer scope is " << x << endl;

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    cout << "\nlocal x in main is " << x <<endl;
    return 0;
}

void useLocal(void)
{
    int x = 25;

    cout << "\nlocal x is " << x << " on entering useLocal" << endl;
    ++x;
    cout << "local x is " << x << " on exiting useLocal" << endl;
}

void useStaticLocal(void)
{
    static int x = 50;

    cout << "\nlocal static x is " << x << " on entering useStaticLocal" << endl;
    ++x;
    cout << "local static x is " << x << " on exiting useStaticLocal" << endl;
}

void useGlobal(void)
{
    cout << "\nglobel x is " << x << " on entering useGlobal" << endl;
    x *= 10;
    cout << "globel x is " << x << " on exiting useGlobal" << endl;
}
