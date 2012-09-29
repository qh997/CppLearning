#include <iostream>
#include "Chapter09_Chrono.h"

using std::cout;
using std::endl;
using std::ostream;
using namespace Chrono;

#define SHOW_VAR(var) cout << #var" = " << var << endl;

int main()
{
    Date holiday(1978, Date::jul, 4);
    Date def;

    SHOW_VAR(holiday);
    SHOW_VAR(def);

    Date inval(2012, Date::feb, 21);

    SHOW_VAR(leapyear(2008));

    return 0;
}
