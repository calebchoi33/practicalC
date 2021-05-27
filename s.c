#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char *argv[]) {
    int yPos = 0, xPos = 0, maxX, maxY, random; 
    int y[3], x[3];

    initscr();
    cbreak();
    noecho();
    clear();
    attron(A_BOLD);

    maxX = LINES - 1;
    maxY = COLS - 1;

    y[0] = 0;
    x[0] = 0;
    y[2] = maxX;
    x[2] = maxY/2;
    y[1] = 0;
    x[1] = maxY;

    for (long i = 0; i < 10000; i++) {
        random = rand();
        int point = random % 3;
        yPos = (yPos + y[point])/2;
        xPos = (xPos + x[point])/2;
        if(point == 1){
            mvaddch(yPos, xPos, '/');
        }else if(point == 2){
            mvaddch(yPos, xPos, "T");
        }else{
            mvaddch(yPos, xPos, ".");
        }
        
        usleep(1000);
        refresh();
    }
    move(0,0);
    //refresh();
    getch();
    endwin();
    exit(0);
}
