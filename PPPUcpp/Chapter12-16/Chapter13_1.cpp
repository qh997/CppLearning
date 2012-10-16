#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), 600, 400, "Canvas");

    Circle c1(Point(100, 200), 50);
    Circle c2(Point(150, 200), 100);
    Circle c3(Point(200, 200), 150);
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);

    Ellipse e1(Point(470, 200), 50, 50);
    Ellipse e2(Point(470, 200), 100, 50);
    Ellipse e3(Point(470, 200), 100, 150);
    win.attach(e1);
    win.attach(e2);
    win.attach(e3);

    Marked_polyline mpl("1234");
    mpl.add(Point(100, 100));
    mpl.add(Point(150, 200));
    mpl.add(Point(250, 250));
    mpl.add(Point(300, 200));
    win.attach(mpl);

    Mark m1(Point(100, 200), 'x');
    Mark m2(Point(150, 200), 'y');
    Mark m3(Point(200, 200), 'z');
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);

    win.wait_for_button();
}

/* Compile command
g++ -I/usr/local/include -I/usr/local/include/FL/images
    -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
    -o 'Chapter12' 'Chapter12.cpp' libbookgui.a /usr/local/lib/libfltk.a
    -lXext -lpthread -ldl -lm -lX11 -lfltk_images -Wno-deprecated

g++ -o 'run' 'Chapter13_1.cpp' libbookgui.a -lfltk_images -Wno-deprecated
*/
