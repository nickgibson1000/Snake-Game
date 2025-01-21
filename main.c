#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>


#include "snake.h"
#include "window.h"
#include "constants.h"

int main(void) {

    // Seed random number generator with time
    // Will be used later in program to generate random coordinates for apple
    srand(time(NULL));

    // Create our game window
    WINDOW *game_win;

    // Create our score window
    WINDOW *score_win;

    // Initialize the window and display it
    initscr();

    // Disables line buffering for window
    cbreak();

    // Print ascii art at the top of the window
    snake_ascii_art();

    // This enables special key processing (arrow keys)
    keypad(stdscr, TRUE);

    // Prevents user input from being displayed to screen
    noecho();

    printw("Press q to quit the game.");
    refresh();

    // Create a new window for our terminal with size specifications
    game_win = create_new_game_win(GAME_HEIGHT, GAME_WIDTH, GAME_STARTy, GAME_STARTx);

    score_win = create_new_score_win(SCORE_HEIGHT, SCORE_WIDTH, SCORE_STARTy, SCORE_STARTx);

    // Game score
    int game_score = 0;

    // High score
    int high_score = 0;
    

    // Error Handling: If Window is null and something went wrong
    if(game_win == NULL) {
        fprintf(stderr, "Game window cannot be created.");
        return EXIT_FAILURE;
    }
    // Exit program if score window cannot be created
    if(score_win == NULL) {
        fprintf(stderr, "Score window cannot be created.");
        return EXIT_FAILURE;
    }


    // Intialize position coords for our score window
    Position current_score_coords;
    Position high_score_coords;


    // Initialize head of snake
    Snake head;

    // Intialize food
    Food food;

    // Initialize the game using our terminal window we created
    init_game(game_win, &head, &food);

    // Intialize the score window 
    init_score(score_win, &current_score_coords, &high_score_coords, game_score, high_score);

    int ch;

    int direction = KEY_RIGHT; // Intial direction snake faces

    // Set a delay for game loop
    timeout(DELAY);

    // Read in user input, end the game if 'q' is pressed on keyboard
    while((ch = getch()) != 'q') {

        // Update direction based on user input
        switch(ch) {

            case KEY_UP: direction = KEY_UP; break;

            case KEY_DOWN: direction = KEY_DOWN; break;

            case KEY_RIGHT: direction = KEY_RIGHT; break;       

            case KEY_LEFT: direction = KEY_LEFT; break; 
        }

        // Update snake position based on current direction
        switch(direction) {

            case KEY_UP: head.coords.y--; break;

            case KEY_DOWN: head.coords.y++; break;

            case KEY_RIGHT: head.coords.x++; break;       
                
            case KEY_LEFT: head.coords.x--; break;
        }

        // Update the game state
        update_game(game_win, &head, &food, &game_score);

        // Update score state
        update_score(score_win, current_score_coords, high_score_coords, game_score, high_score);

        // If snakes collides with the border end the game
        if(check_collision_with_border(head.coords)) {
            break;
        }
    }

    //free_snake_memory(&head);

    // Deallocate memory from windows
    delwin(game_win);
    delwin(score_win);

    // Terminate ncurses mode and restore terminal to default
    endwin();

    return EXIT_SUCCESS;
}