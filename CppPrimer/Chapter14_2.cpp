#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl;

class SmallInt
{
  public:
    SmallInt(int i = 0, string s = "Zero"): val(i), str(s)
    {
        if (i < 0 || i > 255)
            throw out_of_range("Bad SmallInt initializer");
    }
    operator int() const {return val;}
    operator string() const {return str;}

  private:
    size_t val;
    string str;
};

int main()
{
    SmallInt si(25, "Twenty Five");
    SHOW_VAR(si);
    SHOW_VAR(string(si));

    return EXIT_SUCCESS;
}
