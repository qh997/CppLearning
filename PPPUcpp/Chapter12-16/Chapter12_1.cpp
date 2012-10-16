#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl(100, 100);

    Simple_window win(tl, 600, 400, "Canvas");

    Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
    win.attach(xa);
    win.set_label("Canvas #2");

    Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");

    Function sina(sin, 0, 100, Point(20, 150), 1000, 50, 50);
    win.attach(sina);
    win.set_label("Canvas #4");
    sina.set_color(Color::blue);

    Polygon poly;
    poly.add(Point(300, 200));
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("Canvas #5");

    Rectangle r(Point(200, 200), 100, 50);
    win.attach(r);
    win.set_label("Canvas #6");

    Closed_polyline poly_rect;
    poly_rect.add(Point(100, 50));
    poly_rect.add(Point(200, 50));
    poly_rect.add(Point(200, 100));
    poly_rect.add(Point(100, 100));
    poly_rect.add(Point(50, 75));
    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Canvas #7");

    Text t(Point(150, 150), "Hello, graphical world!");
    win.attach(t);
    win.set_label("Canvas #8");

    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);
    win.set_label("Canvas #9");

    win.wait_for_button();
}

/* Compile command
g++ -I/usr/local/include -I/usr/local/include/FL/images
    -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
    -o 'Chapter12' 'Chapter12.cpp' libbookgui.a /usr/local/lib/libfltk.a
    -lXext -lpthread -ldl -lm -lX11 -lfltk_images -Wno-deprecated

g++ -o 'run' 'Chapter12.cpp' libbookgui.a -lfltk_images -Wno-deprecated
*/
