// Works only in Unix systems
// Basically updates a concrete place of terminal

#include <stdio.h>

int main() {
    char table[] = "abcdefghijklmnop";
    int W = 50, H = 20;
    for (;;) {
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                putc(table[(x + y) % (sizeof(table) - 1)], stdout);
            }
            putc('\n', stdout);
        } 
        printf("\033[%dA", H);
        printf("\033[%dD", W);
    }

    return 0;
}