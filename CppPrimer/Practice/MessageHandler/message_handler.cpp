#include <iostream>
#include "Message.h"
#include "Folder.h"

using namespace std;

int main()
{
    Folder f1("lixue");
    Folder f2("qiuqing");

    Message m1("Hello gengs!");
    Message m2("Start!");

    m1.save(f1);
    m1.save(f2);

    m1.show();
}
