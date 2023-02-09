#ifndef LOOP
#define LOOP

#include <stdio.h>

#ifdef __unix__

    #include <unistd.h> // used for usleep

    void loop(int W, int H) {
        usleep(1000 * 1000/60); // 60 fps update
        printf("\033[%dA", H);  // snap cursor to first written line
        printf("\r");           // snap to start of line 
    }

#else

    #include <windows.h> // used for Sleep in milliseconds

    void loop(int W, int H) {
        Sleep(1000./60.); // 60 fps update
        HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE); // get stdout handle
        CONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo;
        GetConsoleScreenBufferInfo(StdOut, &lpConsoleScreenBufferInfo);
        COORD c = lpConsoleScreenBufferInfo.dwCursorPosition;
        SetConsoleCursorPosition(StdOut, (COORD) {c.X, c.Y - H});
    }

#endif
#endif