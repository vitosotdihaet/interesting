#ifndef CHARS
#define CHARS

#include "../loop.h"

void char_example(int W, int H) {
    char table[] = "abcdefghijklmnop";
    for (int counter = 0; counter < 200; ++counter) {
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                putc(table[(x + y + counter) % (sizeof(table) - 1)], stdout);
            }
            putc('\n', stdout);
        }
        loop(W, H);
    }
}

#endif