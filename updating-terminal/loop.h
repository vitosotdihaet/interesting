#ifndef LOOP_H
#define LOOP_H

#include <stdio.h>

#ifdef __unix__

    #include <unistd.h> // used for usleep

    void loop(short W, short H) {
        usleep(1000 * 1000/60); // 60 fps update
        printf("\033[%dA", H);  // snap cursor to first written line
        printf("\r");           // snap to start of line 
    }

#else

    #include <windows.h> // used for Sleep in milliseconds

    void loop(short W, short H) {
        Sleep(1000./60.); // 60 fps update
        HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo;
        GetConsoleScreenBufferInfo(StdOut, &lpConsoleScreenBufferInfo);
        COORD c = lpConsoleScreenBufferInfo.dwCursorPosition;
        SetConsoleCursorPosition(StdOut, (COORD) {c.X, c.Y - H});
    }

#endif

#endif // LOOP_H