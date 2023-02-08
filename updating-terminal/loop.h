#ifndef LOOP
#define LOOP

#include <stdio.h>

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
#endif