#include "snake.h"
#include "window.h"
#include "constants.h"

// Good
void snake_ascii_art(void) {

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Green forground, black background

    
    // Set text color to green
    attron(COLOR_PAIR(1)); 

    printw("   ____             _        \n");
    printw(" / ____|           | |       \n");
    printw("| (___  _ __   __ _| | _____ \n");
    printw(" \\___ \\| '_ \\ / _` | |/ / _ \\ \n");
    printw(" ____) | | | | (_| |   <  __/ \n");
    printw("|_____/|_| |_|\\__,_|_|\\_\\___| \n");
                              
                              
    // Reset text color to default
    attroff(COLOR_PAIR(1));
}

// Good
WINDOW *create_new_game_win(int game_height, int game_width, int game_starty, int game_startx) {

    // Creates a new window with our passed in parameter specifications
    WINDOW *game_win = newwin(game_height, game_width, game_starty, game_startx);

    /**
     * Puts a box around the entire window.
     * 
     * Parameters:
     * - local_win: The window to draw the box around.
     * - '|': Character used for the vertical borders of the box.
     * - '-': Character used for the horizontal borders of the box.
     */
    box(game_win, 0, 0);
    wrefresh(game_win);

    return game_win;

}

// Good
WINDOW *create_new_score_win(int score_height, int score_width, int score_starty, int score_startx) {

    WINDOW *score_win = newwin(SCORE_HEIGHT, SCORE_WIDTH, SCORE_STARTy, SCORE_STARTx);

    //box(score_win, 0, 0);
    wrefresh(score_win);
    return score_win;

}
// Good
void init_score(WINDOW *score_win, Position *current_score_coords, Position *high_score_coords, int game_score, int high_score) {

    wmove(score_win, 2, 2);

    current_score_coords->y = 2;
    current_score_coords->x = 2;

    wprintw(score_win, "Score: %i", game_score);
    wmove(score_win, 4, 2);

    high_score_coords->x = 2;
    high_score_coords->y = 4;

    wprintw(score_win, "High Score: %i ", high_score);
    wrefresh(score_win);
}

// Good
void update_score(WINDOW *score_win, Position current_score_coords, Position high_score_coords, int game_score, int high_score) {


    wmove(score_win, current_score_coords.y, current_score_coords.x);

    wprintw(score_win, "Score: %i", game_score);

    wmove(score_win, high_score_coords.y, high_score_coords.x);

    wprintw(score_win, "High Score: %i", high_score);

    wrefresh(score_win);
}


// Good
void init_game(WINDOW *game_win, Snake *head, Food *food) {

    init_snake(game_win, head);

    init_food(game_win, food);
    
    // Hide the cursor from the screen
    curs_set(0);

    // Refresh the window to display changes
    wrefresh(game_win);
}

// Good
void update_game(WINDOW *game_win, Snake *head, Food *food, int *game_score) {

    // Erase our game window to update the snake and apple positions
    werase(game_win); 

    // Redraw box around window because werase() erases everything
    box(game_win, 0, 0);

    // Refresh window too display changes
    wrefresh(game_win);

    // Move cursor too the new location of the snake and print it 
    wmove(game_win, head->coords.y, head->coords.x);
    wprintw(game_win, "O");
    
    // Move cursor too the location of the apple and print it 
    wmove(game_win, food->coords.y, food->coords.x);
    wprintw(game_win, "A");

    

    // If apple is eaten, we move the apple to new coordinates in the game window
    if(head->coords.y == food->coords.y && head->coords.x == food->coords.x) {

        // Add new segment too the snake for eating the food
        add_snake_segment(head);

        // Update all cordinates of the snake to be proper
        update_snake_coords()

        print_snake_body();


        // Overwrite current apple location with a an empty character
        mvwaddch(game_win, food->coords.y, food->coords.x, 'a');

        wmove(game_win, head->coords.y, head->coords.x);

        wprintw(game_win, "O");

        wrefresh(game_win);

        // Gets new random coordinates for the apple
        int random_x_coord = get_random_x_coord();
        int random_y_coord = get_random_y_coord();

        // Move cursor to random location in window
        wmove(game_win, random_y_coord, random_x_coord);

        
        food->coords.y = random_y_coord;
        food->coords.x = random_x_coord;
        
        // Reprint the apple to the window
        wprintw(game_win, "A");

        wrefresh(game_win);

        (*game_score)++;
    }

    wrefresh(game_win);
}

int get_random_x_coord(void) {


    // This gives us the range of x coords 
    int max_x = GAME_WIDTH - 1; // Right side
    int min_x = 1; // Left side

    int x = (rand() % (max_x - min_x)) + min_x;

    return x;
}

int get_random_y_coord(void) {

    // This gives us the range of y coords
    int max_y = GAME_HEIGHT - 1; // Bottom side
    int min_y = 1; // Top side

    int y = (rand() % (max_y - min_y)) + min_y;


    return y;
}

// Good
bool check_collision_with_border(Position snake_coords) {

    // This gives us the range of x coords
    int max_x = GAME_WIDTH - 1; // Right side
    int min_x = 0; // Left side

    // Check x-coords
    if(snake_coords.x == max_x || snake_coords.x == min_x) {
        return true;
    }

    // This gives us the range of y coords
    int max_y = GAME_HEIGHT - 1; // Bottom side
    int min_y = 0; // Top side

    // Checks y-coords
    if(snake_coords.y == max_y || snake_coords.y == min_y) {
        return true;
    }

    // Return false if not collisons detected
    return false;
}

void init_snake(WINDOW *game_win, Snake *head) {

    // Move our cursor inside the window at specified coords (Y,X) to print snake
    wmove(game_win, 9,8); 
    wprintw(game_win, "O"); // Print the snake to the window

    // Update our coordinates structure with starting snake position
    head->coords.x = 8;
    head->coords.y = 9;

    //wrefresh(game_win);

}

// Good
void init_food(WINDOW *game_win, Food *food) {

    // Move our cursor inside the window at specified coords (Y,X) to print apple
    wmove(game_win, 9, 30);
    wprintw(game_win, "A"); // Print the apple to the window
    
    // Update our coordinates structure with starting apple position
    food->coords.y = 9;
    food->coords.x = 30;

    //wrefresh(game_win);
}




void add_snake_segment(Snake *head) {

    Snake *current = head->next;

    if(head->next == NULL) {

        Snake *new_segment = malloc(sizeof(Snake));

        if(new_segment == NULL) {
            perror("Error allocating memory for new segment...");
            exit(EXIT_FAILURE);
        }

        head->next = new_segment;
        new_segment->next = NULL;

        new_segment->coords.x = current->coords.x; // Set to the last segment's x
        new_segment->coords.y = current->coords.y; // Set to the last segment's y

        // MAYBE UPDATE COORDS????
    } else {

        while(current->next != NULL) {

            current = current->next;
        }

        Snake *new_segment = malloc(sizeof(Snake));

        if(new_segment == NULL) {
            perror("Error allocating memory for new segment...");
            exit(EXIT_FAILURE);
        }

        new_segment->coords.x = current->coords.x; // Set to the last segment's x
        new_segment->coords.y = current->coords.y; // Set to the last segment's y
        
        current->next = new_segment;
        new_segment->next = NULL;
    }
}


void update_snake_coords(Snake *head, Position prev_head_coords) {

    
}




// Call free on each snake segmenet too free all allocated memory
void free_snake_memory(Snake *head) {

    Snake *current = head;

    while(current != NULL) {

        Snake *next = current->next;

        free(current);
        current = next;
    }

}


