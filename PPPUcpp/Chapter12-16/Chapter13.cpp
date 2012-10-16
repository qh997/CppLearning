#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Simple_window win1(Point(100, 100), 600, 400, "Canvas");

    int x_size = win1.x_max();
    int y_size = win1.y_max();
    int x_grid = 80;
    int y_grid = 40;

    Lines grid;
    for (int x = 0; x < x_size; x += x_grid)
        grid.add(Point(x, 0), Point(x, y_size));
    for (int y = 0; y < y_size; y += y_grid)
        grid.add(Point(0, y), Point(x_size, y));
    grid.set_color(Color::red);
    grid.set_style(Line_style(Line_style::dash, 2));
    win1.attach(grid);

    Polygon poly;
    poly.add(Point(100, 100));
    poly.add(Point(150, 200));
    poly.add(Point(250, 300));
    poly.add(Point(300, 200));
    win1.attach(poly);

    Rectangle rect00(Point(150, 100), 200, 100);
    Rectangle rect11(Point(50, 50), Point(250, 150));
    Rectangle rect12(Point(50, 150), Point(250, 250));
    Rectangle rect21(Point(250, 50), 200, 100);
    Rectangle rect22(Point(250, 150), 200, 100);

    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    rect00.set_color(Color::invisible);
    rect11.set_color(Color::invisible);
    rect12.set_color(Color::invisible);
    rect21.set_color(Color::invisible);
    rect22.set_color(Color::invisible);

    win1.attach(rect00);
    win1.attach(rect11);
    win1.attach(rect12);
    win1.attach(rect21);
    win1.attach(rect22);

    rect11.move(400, 0);
    rect11.set_fill_color(Color::white);
    win1.set_label("rectangles 2");
    win1.put_on_top(rect00);
    win1.set_label("rectangles 3");

    Vector_ref<Rectangle> vr;
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
        {
            vr.push_back(new Rectangle(Point(i * 20, j * 20), 20, 20));
            vr[vr.size() - 1].set_fill_color(i * 16 + j);
            win1.attach(vr[vr.size() - 1]);
        }

    Text t(Point(200, 200), "A closed polyline that isn't a polygon");
    t.set_color(Color::blue);
    win1.attach(t);

    win1.wait_for_button();
}

/* Compile command
g++ -I/usr/local/include -I/usr/local/include/FL/images
    -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
    -o 'Chapter12' 'Chapter12.cpp' libbookgui.a /usr/local/lib/libfltk.a
    -lXext -lpthread -ldl -lm -lX11 -lfltk_images -Wno-deprecated

g++ -o 'run' 'Chapter13.cpp' libbookgui.a -lfltk_images -Wno-deprecated
*/
