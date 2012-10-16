#include "Simple_window.h"
#include "Graph.h"

double one(double) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}

int main()
{
    using namespace Graph_lib;

    const int xmax = 600;
    const int ymax = 400;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig, y_orig);

    const int r_min = -9;
    const int r_max = 9;

    const int n_points = 400;

    const int x_scale = 30;
    const int y_scale = 30;

    const int xlength = xmax-40;
    const int ylength = ymax-40;

    Simple_window win(Point(100, 100), xmax, ymax, "Function graphing");

    Function s(one, r_min, r_max, orig, n_points, x_scale, y_scale);
    Function s2(slope, r_min, r_max, orig, n_points, x_scale, y_scale);
    Function s3(square, r_min, r_max, orig, n_points, x_scale, y_scale);
    win.attach(s);
    win.attach(s2);
    win.attach(s3);

    Text ts(Point(100, y_orig-40), "one");
    Text ts2(Point(100, y_orig+y_orig/2-20), "x/2");
    Text ts3(Point(x_orig-100, 20), "x*x");
    win.attach(ts);
    win.attach(ts2);
    win.attach(ts3);

    Axis x(Axis::x, Point(20, y_orig), xlength, xlength/x_scale, "one touch == 1");
    Axis y(Axis::y, Point(x_orig, ylength+20), ylength, ylength/y_scale, "one touch == 1");
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);

    Function s4(cos, r_min, r_max, orig, n_points, x_scale, y_scale);
    s4.set_color(Color::blue);
    win.attach(s4);
    Function s5(sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale);
    win.attach(s5);
    x.label.move(-160, 0);
    x.notches.set_color(Color::dark_red);

    Function f1(log, 0.01, r_max, orig, 200, 30, 30);
    Function f2(sin, r_min, r_max, orig, n_points, x_scale, y_scale);
    Function f4(exp, r_min, 3, orig, n_points, x_scale, y_scale);
    win.attach(f1);
    win.attach(f2);
    win.attach(f4);

    win.set_label("Function graphing: label functions");
    win.wait_for_button();
}

/* Compile command
g++ -I/usr/local/include -I/usr/local/include/FL/images
    -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
    -o 'Chapter12' 'Chapter12.cpp' libbookgui.a /usr/local/lib/libfltk.a
    -lXext -lpthread -ldl -lm -lX11 -lfltk_images -Wno-deprecated

g++ -o 'run' 'Chapter15.cpp' libbookgui.a -lfltk_images -Wno-deprecated
*/
