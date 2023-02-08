#ifndef SINUS
#define SINUS

#include "../loop.h"
#include <math.h>

#define PI 3.1415962
#define EPS 0.15

void sin_example(int W, int H) {
    long double dx = PI / 10.;
    long double dy = 2.4 / H;
    for (long double offset = 0.; offset < 50.; offset += dx) {
        for (long double y = 1.2; y > -1.2; y -= dy) {
            for (long double x = offset; x < offset + W * dx; x += dx) {
                long double cy = sin(x);
                if (y + EPS >= cy && cy >= y - EPS) putc('#', stdout);
                else putc(' ', stdout);
            }
            putc('\n', stdout);
        }
        loop(W, H);
    }
}

#endif