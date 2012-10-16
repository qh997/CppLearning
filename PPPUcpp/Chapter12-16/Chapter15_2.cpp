#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

const int xmax = 600;
const int ymax = 400;

const int xoffset = 100;
const int yoffset = 60;

const int xspace = 40;
const int yspace = 40;

const int xlength = xmax - xoffset - xspace;
const int ylength = ymax - yoffset - yspace;

const int base_year = 1960;
const int end_year = 2040;

const double xscale = double(xlength)/(end_year - base_year);
const double yscale = double(ylength)/100;

struct Distribution
{
    int year, young, middle, old;
};

istream &operator>>(istream &is, Distribution &d)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.year
           >> ch2 >> dd.young >> dd.middle >> dd.old
           >> ch3)
    {
        if (ch1 != '(' || ch2 != ':' || ch3 != ')')
        {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
        return is;
    d = dd;
    return is;
}

class Scale
{
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s): cbase(b), vbase(vb), scale(s) {}
    int operator()(int v) const {return cbase + (v - vbase) * scale;}
};

int main()
{
    string file_name = "japanese-age-data.txt";
    ifstream ifs(file_name.c_str());
    if (!ifs)
        error("can't open ", file_name);

    Scale xs(xoffset, base_year, xscale);
    Scale ys(ymax - yoffset, 0, -yscale);

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;

    Distribution d;
    while (ifs >> d)
    {
        if (d.year < base_year || end_year < d.year)
            error("year out of range");
        if (d.young + d.middle + d.old != 100)
            error("percentages don't add up");
        int x = xs(d.year);
        children.add(Point(x, ys(d.young)));
        adults.add(Point(x, ys(d.middle)));
        aged.add(Point(x, ys(d.old)));
    }

    Graph_lib::Window win(Point(100, 100), xmax, ymax, "Aging Japan");

    Text children_label(Point(20,children.point(0).y), "age 0-14");
    children.set_color(Color::red);
    children_label.set_color(Color::red);

    Text adults_label(Point(20,adults.point(0).y), "age 15-64");
    adults.set_color(Color::blue);
    adults_label.set_color(Color::blue);

    Text aged_label(Point(20,aged.point(0).y), "age 65+");
    aged.set_color(Color::dark_green);
    aged_label.set_color(Color::dark_green);

    Axis x(Axis::x, Point(xoffset, ymax-yoffset), xlength,
           (end_year - base_year)/10,
           "year    1960    1970     1980     1990      "
           "2000      2010     2020      2030     2040");
    x.label.move(-100, 0);
    Axis y(Axis::y, Point(xoffset, ymax-yoffset), ylength, 10, "% of population");
    Line current_year(Point(xs(2008), ys(0)), Point(xs(2008), ys(100)));
    current_year.set_style(Line_style::dash);

    win.attach(children);
    win.attach(adults);
    win.attach(aged);
    
    win.attach(children_label);
    win.attach(adults_label);
    win.attach(aged_label);

    win.attach(x);
    win.attach(y);
    win.attach(current_year);

    gui_main();
}
