//
// Created by C22Andrew.Lee on 11/24/2019.
//

#ifndef MYEXE_FUNCTS_H
#define MYEXE_FUNCTS_H

#endif //MYEXE_FUNCTS_H

#include <stdbool.h>

typedef struct snake{
    int x;
    int y;
    int size;
    int direction;
} snake;
//1 = right
//2 = left
//3 = down
//4 = up

typedef struct food {
    int x;
    int y;
} food;

/**--------------------------------------------------------
 * This function initializes board, ie draws it at beginning
 * @param <food *food, snake *snake, char board[20][50]>
 * these are pointers to the snake and food pointers
 * so they can be updated from within the function, the board param is a
 * pointer to the board
 * @return <void>
 * simply updates the value
 */
void initialize(food *food, snake *snake, char board[][50]);

/**--------------------------------------------------------
 * This physically moves the snake and erases the last position
 * @param <struct snake *snake, char board[20][50]>
 * these are pointers to the snake and board so the position of
 * the snake can be updated,
 * @return <void>
 * simply updates the value
 */
void moveSnake(snake *snake, char board[20][50]);

/**--------------------------------------------------------
 * Draws the new snake and food on the board. As the snake moves,
 * it interacts with board directly so only food location is needed
 * @param <food *food,char board[20][50])>
 * these values are drawn on the board by getting their
 * location based on their pointer
 * @return <void>
 * prints the board to the screen
 */
void draw(food* food,char board[20][50]);

/**--------------------------------------------------------
 * Updates the direction the snake is moving.
 * Like the original snake, the snake CANNOT go in reverse
 * @param <snake *snake>
 * pointer to the snake so the direction can be updated
 * @return <void>
 * simply updates the value
 */
void keyHit(snake *snake);

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
bool checkfood(snake *snake, food *food, char board[20][50]);

/**--------------------------------------------------------
 * Checks to see if the snake hit a border
 * @param <snake *snake>
 * pointer to the snake so location can be gained
 * @return <bool>
 * returns a bool, tru is hit wall and false otherwise
 */
bool checkOver(snake *snake);




