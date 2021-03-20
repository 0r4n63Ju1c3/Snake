//
// Created by C22Andrew.Lee on 11/24/2019.
//

#include "functs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>


/**--------------------------------------------------------
 * This function initializes board, ie draws it at beginning
 * @param <food *food, snake *snake, char board[20][50]>
 * these are pointers to the snake and food pointers
 * so they can be updated from within the function, the board param is a
 * pointer to the board
 * @return <void>
 * simply updates the value
 */
void initialize(food *food, snake *snake, char board[20][50]){
   //starting specs of snake
    snake->x = 5;
    snake->y = 5;
    snake->size = 0;
    snake->direction = 1;

    srand(time(NULL));

    //creates a food in middle of board
    food->x = 25;
    if(food->x % 2 == 0)
        food->x +=1;
    food->y = 10;

    board[snake->x][snake->y] = '0';

    //draws the board initially
    int x,y;
    for(y=0;y<20;y++)
    {
        for(x=0;x<50;x++)
        {
            printf("%c",board[y][x]);
        }
        printf("\n");
    }
}

/**--------------------------------------------------------
 * This physically moves the snake and erases the last position
 * @param <struct snake *snake, char board[20][50]>
 * these are pointers to the snake and board so the position of
 * the snake can be updated,
 * @return <void>
 * simply updates the value
 */
void moveSnake(snake *snake, char board[20][50]){
    board[snake->y][snake->x] = ' ';
    if(snake->direction == 1) {
        snake->x = snake->x + 2;
        board[snake->y][snake->x] = '0';
    }
    if(snake->direction == 2) {
        snake->x = snake->x - 2;
        board[snake->y][snake->x] = '0';
    }
    if(snake->direction == 3) {
        snake->y = snake->y + 1;
        board[snake->y][snake->x] = '0';
    }
    if(snake->direction == 4) {
        snake->y = snake->y - 1;
        board[snake->y][snake->x] = '0';
    }
}


/**--------------------------------------------------------
 * Draws the new snake and food on the board. As the snake moves,
 * it interacts with board directly so only food location is needed
 * @param <food *food,char board[20][50])>
 * these values are drawn on the board by getting their
 * location based on their pointer
 * @return <void>
 * prints the board to the screen
 */
void draw(food* food, char board[20][50]){
    board[food->y][food->x] = 'X';
    int x,y;
    for(y=0;y<20;y++)
    {
        for(x=0;x<50;x++)
        {
            printf("%c",board[y][x]);
        }
        printf("\n");
    }
}

/**--------------------------------------------------------
 * Updates the direction the snake is moving.
 * Like the original snake, the snake CANNOT go in reverse
 * @param <snake *snake>
 * pointer to the snake so the direction can be updated
 * @return <void>
 * simply updates the value
 */
void keyHit(snake *snake){
    //int old = snake->direction;
    if (GetAsyncKeyState(VK_RIGHT)) {
        if (snake->direction != 2){
            snake->direction = 1;
        }
    }

    if (GetAsyncKeyState(VK_DOWN)) {
        if (snake->direction != 4){
            snake->direction = 3;
        }
    }

    if (GetAsyncKeyState(VK_LEFT)) {
        if (snake->direction != 1){
            snake->direction = 2;
        }
    }

    if (GetAsyncKeyState(VK_UP)) {
        if (snake->direction != 3){
            snake->direction = 4;
        }
    }

}
/**--------------------------------------------------------
 * Checks to see if the snake hit a border
 * @param <snake *snake>
 * pointer to the snake so location can be gained
 * @return <bool>
 * returns a bool, tru is hit wall and false otherwise
 */
bool checkOver(snake *snake){
    if(snake->x >= 49 || snake ->x <= 0)
        return true;
    if(snake->y >= 19 || snake ->y <= 0)
        return true;
    return false;
}

/**--------------------------------------------------------
 * Checks to see if the snake and food are in the
 * same location, if they are then a random new food
 * is generated and the old one is removed
 * @param <snake *snake, food *food, char board[20][50]>
 * these values are checked against each other to see if
 * they are overlapping
 * @return <bool>
 * returns true if the snake hit a food
 */
bool checkfood(snake *snake, food *food, char board[20][50]) {
    if ((snake->x == food->x) && (snake->y == food->y)) {
        board[food->y][food->x] = ' ';
        food->x = rand() % 47 + 1;
        if (food->x % 2 == 0)
            food->x += 1;
        food->y = rand() % 18 + 1;
        snake->size += 1;
        return true;
    }
    return false;
}





