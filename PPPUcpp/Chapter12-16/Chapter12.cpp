#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl(100, 100);

    Simple_window win(tl, 600, 400, "Canvas");

    Polygon poly;

    poly.add(Point(300, 200));
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));

    poly.set_color(Color::red);

    win.attach(poly);

    win.wait_for_button();
}

/* Compile command
g++ -I/usr/local/include -I/usr/local/include/FL/images
    -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
    -o 'Chapter12' 'Chapter12.cpp' libbookgui.a /usr/local/lib/libfltk.a
    -lXext -lpthread -ldl -lm -lX11 -lfltk_images -Wno-deprecated

g++ -o 'run' 'Chapter12.cpp' libbookgui.a -lfltk_images -Wno-deprecated
*/
