#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

// This structure will be used to hold coordinate points to move various items around game/score windows 
typedef struct {
    int x;
    int y;
} Position;

/**
 * Creates a new window with passed in parameters
 * height: Height of the window
 * width: Width of the window
 * starty: y coordinate window will start at and anchor too
 * startx: x coordinate window will start at and anchor too
 */
WINDOW *create_new_game_win(int game_height, int game_width, int game_starty, int game_startx);


WINDOW *create_new_score_win(int score_height, int score_width, int score_starty, int score_startx);

#endif // WINDOW_H