// Basically updates a concrete place of terminal

#include <stdio.h>
#include <math.h>   // used for sin example

#ifdef __unix__

#include <unistd.h> // used for usleep

void loop(int W, int H) {
    usleep(1000 * 1000/60); // 60 fps update
    printf("\033[%dA", H);  // snaps cursor to start of line
    printf("\033[%dD", W);  // delete all chars
}

#else

#include <windows.h> // used for Sleep in milliseconds

void loop(int W, int H) {
    Sleep(1000./60.); // 60 fps update
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE); // get stdout handle
    CONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo;
    GetConsoleScreenBufferInfo(StdOut, &lpConsoleScreenBufferInfo);
    short y = lpConsoleScreenBufferInfo.dwCursorPosition.Y;
    SetConsoleCursorPosition(StdOut, (COORD) {0, y - H});
}

#endif

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

int main() {
    int W = 50, H = 20;
    sin_example(W, H);

    return 0;
}