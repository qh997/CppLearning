#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

int main()
{
    const int arraySize = 10;
    int data[arraySize] = {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};

    cout << "Unsort array:" << endl;
    for (int i = 0; i < arraySize; ++i)
        cout << setw(4) << data[i];
    cout << endl;

    for (int next = 1; next < arraySize; ++next)
    {
        int moveItem = next;
        int insert = data[next];

        while (insert < data[moveItem - 1] && moveItem > 0)
        {
            data[moveItem] = data[moveItem - 1];
            --moveItem;
        }

        data[moveItem] = insert;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < arraySize; ++i)
        cout << setw(4) << data[i];
    cout << endl;

    return 0;
}
