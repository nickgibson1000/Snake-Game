#ifndef SNAKE_H
#define SNAKE_H


#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "window.h"

struct Snake;

typedef struct Snake {
    Position coords;
    struct Snake *next;
} Snake;

typedef struct {
    Position coords;
} Food;

// Intialize the game state for snake
// Makes calls to init_snake and init_food to place snake and food in window to begin the game
void init_game(WINDOW *game_win, Snake *head, Food *food);

void update_game(WINDOW *game_win, Snake *head, Food *food, int *game_score);

void init_score(WINDOW *score_win, Position *current_score_coords, Position *high_score_coords, int game_score, int high_score);

void update_score(WINDOW *score_win, Position current_score_coords, Position high_score_coords, int game_score, int high_score);

void init_snake(WINDOW *game_win, Snake *head);

void init_food(WINDOW *game_win, Food *food);

int get_random_x_coord(void);

int get_random_y_coord(void);

bool check_collision_with_border(Position snake_coords);

void snake_ascii_art(void);

void add_snake_segment(Snake *head);

void update_snake_coords(Snake *head, Position prev_head_coords);


//Free all memory allocated to snake during segment creation
void free_snake_memory(Snake *head);


#endif // SNAKE_H