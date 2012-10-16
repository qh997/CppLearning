#include <sstream>
#include "Simple_window.h"
#include "Graph.h"

int fac(int n)
{
    int r = 1;
    while (n > 1)
    {
        r *= n;
        --n;
    }

    return r;
}

double term(double x, int n)
{
    return pow(x, n)/fac(n);
}

double expe(double x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += term(x, i);
    return sum;
}

int expN_number_of_terms = 10;

double expN(double x)
{
    return expe(x, expN_number_of_terms);
}

int main()
{
    using namespace Graph_lib;

    const int xmax = 600;
    const int ymax = 400;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig, y_orig);

    const int r_min = -9;
    const int r_max = 3;

    const int n_points = 200;

    const int x_scale = 30;
    const int y_scale = 30;

    const int xlength = xmax-40;
    const int ylength = ymax-40;

    Simple_window win(Point(100, 100), xmax, ymax, "Function graphing");

    Axis x(Axis::x, Point(20, y_orig), xlength, xlength/x_scale, "one touch == 1");
    Axis y(Axis::y, Point(x_orig, ylength+20), ylength, ylength/y_scale, "one touch == 1");
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);

    Function real_exp(exp, r_min, r_max, orig, n_points, x_scale, y_scale);
    real_exp.set_color(Color::blue);
    win.attach(real_exp);

    for (int n = 0; n < 50; ++n)
    {
        ostringstream ss;
        ss << "exp approximation; n==" << n;
        win.set_label(ss.str().c_str());
        expN_number_of_terms = n;
        Function e(expN, r_min, r_max, orig, n_points, x_scale, y_scale);
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }
}

/* Compile command
g++ -I/usr/local/include -I/usr/local/include/FL/images
    -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
    -o 'Chapter12' 'Chapter12.cpp' libbookgui.a /usr/local/lib/libfltk.a
    -lXext -lpthread -ldl -lm -lX11 -lfltk_images -Wno-deprecated

g++ -o 'run' 'Chapter15.cpp' libbookgui.a -lfltk_images -Wno-deprecated
*/
