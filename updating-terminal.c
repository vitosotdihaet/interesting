// Works only in Unix systems
// Basically updates a concrete place of terminal

#include <stdio.h>
#include <unistd.h>

int main() {
    char table[] = "abcdefghijklmnop";
    int W = 50, H = 20, counter = 0;
    for (counter = 0; counter < 200; ++counter) {
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                putc(table[(x + y + counter) % (sizeof(table) - 1)], stdout);
            }
            putc('\n', stdout);
        }
        usleep(1000*1000/60);  // 60 fps update
        printf("\033[%dA", H); // snaps cursor to start of line
        printf("\033[%dD", W); // delete all chars
    }

    return 0;
}