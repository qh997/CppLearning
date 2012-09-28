#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

/* Grammar
Expression:
    Term
    Expression + Term
    Expression - Term
Term
    Primary
    Term * Primary
    Term / Primary
    Term % Primary
Primary
    Number
    ( Expression )
    + Primary
    - Primary
Number
    floating-point-literal
*/

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';
const char let = 'L';
const string declkey = "let";

class Token
{
  public:
    Token(char ch, double val = 0)
        : kind(ch), value(val) {}
    Token(char ch, string n)
        : kind(ch), name(n) {}

    char kind;
    double value;
    string name;
};

class Token_stream
{
  public:
    Token_stream(): full(false), buffer(0) {}
    Token get()
    {
        if (full)
        {
            full = false;
            return buffer;
        }

        char ch;
        cin >> ch;
        switch (ch)
        {
            case print:
            case quit:
            case '(':case ')':
            case '+':case '-':
            case '*':case '/':case '%':
            case '=':
                return Token(ch);

            case '.':
            case '0':case '1':case '2':case '3':case '4':
            case '5':case '6':case '7':case '8':case '9':
            {
                cin.putback(ch);
                double val;
                cin >> val;
                return Token('8', val);
            }

            default:
                if(isalpha(ch))
                {
                    cin.putback(ch);
                    string s;
                    cin >> s;
                    if (s == declkey)
                        return Token(let);
                    return Token(name, s);
                }
                throw std::runtime_error("Bad token");
        }
    }
    void putback(Token t)
    {
        if (full)
            throw std::runtime_error("putback() into a full buffer");

        buffer = t;
        full = true;
    }
    void ignore(char c)
    {
        if (full && c == buffer.kind)
        {
            full = false;
            return;
        }
        full = false;

        char ch = 0;
        while (cin >> ch)
            if (ch == c)
                return;
    }

  private:
    bool full;
    Token buffer;
};

class Variable
{
  public:
    string name;
    double value;
    Variable(string n, double v): name(n), value(v) {}
};

void calculate();
double statement();
double declaration();
void clean_up_mess();
double get_value(string s);
void set_value(string s, double d);
bool is_declared(string s);
double define_name(string s, double d);
double expression();
double term();
double primary();

Token_stream ts;
vector<Variable> var_table;

int main()
{
    try
    {
        calculate();
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "exception" << endl;
        return 2;
    }

    return 0;
}

void calculate()
{
    while (cin)
    try
    {
        cout << prompt;
        Token t = ts.get();

        while (t.kind == print)
            t = ts.get();

        if (t.kind == quit)
        {
            cout << endl;
            return;
        }
        
        ts.putback(t);

        cout << result << statement() << endl;
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
        case let:
            return declaration();

        default:
            ts.putback(t);
            return expression();
    }
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name)
        throw std::runtime_error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')
        throw std::runtime_error("= missing in declaration of " + var_name);

    double d = expression();
    return define_name(var_name, d);
}

void clean_up_mess()
{
    ts.ignore(print);
}

double get_value(string s)
{
    for (vector<Variable>::iterator i = var_table.begin();
         i != var_table.end(); ++i)
        if (i->name == s) return i->value;

    throw std::runtime_error("get undefined value: " + s);
}

void set_value(string s, double d)
{
    for (vector<Variable>::iterator i = var_table.begin();
         i != var_table.end(); ++i)
        if (i->name == s)
        {
            i->value = d;
            return;
        }

    throw std::runtime_error("set undefined value: " + s);
}

bool is_declared(string s)
{
    for (vector<Variable>::iterator i = var_table.begin();
         i != var_table.end(); ++i)
        if (i->name == s) return true;

    return false;
}

double define_name(string s, double d)
{
    if (is_declared(s))
        throw std::runtime_error("duplicate definition: " + s);

    var_table.push_back(Variable(s, d));
    return d;
}

double expression()
{
    double left = term();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
            case '+':
                left += term();
                break;

            case '-':
                left -= term();
                break;

            default:
                ts.putback(t);
                return left;
        }

        t = ts.get();
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
            case '*':
                left *= primary();
                break;

            case '/':
            {
                double d = primary();
                if (0 == d)
                    throw std::runtime_error("divide by zero");
                left /= d;
                break;
            }

            case '%':
            {
                double d = primary();
                int i1 = int(left);
                if (i1 != left)
                    throw std::runtime_error("left-hand operand of % not int");
                int i2 = int(d);
                if (i2 != d)
                    throw std::runtime_error("right-hand operand of % not int");
                if (i2 == 0)
                    throw std::runtime_error("%:divide by zero");
                left = i1 % i2;
                break;
            }

            default:
                ts.putback(t);
                return left;
        }

        t = ts.get();
    }
}

double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                throw std::runtime_error("')'expected");
            return d;
        }

        case number:
            return t.value;

        case '+':
            return primary();

        case '-':
            return -primary();

        default:
            throw std::runtime_error("primary expected");
    }
}
