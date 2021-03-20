//
// Created by C22Andrew.Lee on 11/24/2019.
//
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "functs.h"
#include <stdbool.h>
#include <unistd.h>


//TODO: make a start menu
//TODO: Have an empty game board
//TODO: Get the snake moving and change direction
//TODO: Check if snake hits boundary
//TODO: Check if the snake hits itself
//TODO: Draw and update food
//TODO: make variable to keep track of score and player name
//TODO: store the score in a file - read and write
//TODO: Get the highest score

int main(){
    char map[20][50] = {"##################################################",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "#                                                #",
                        "##################################################"};

   snake snake1;
   food food1;

   printf("Welcome to blinky snake\n");
   printf("There are a couple of rules\n");
   printf("1) You must collect food ->\n");
   printf("the first food eaten does not grow the snake, this is a tester to make sure you know how to play the game and will spawn in the middle\n");
   printf("2) the more food you get the more blinky it gets\n");
   printf("this is because I used only printf statements and there are a lot of calculations running in the back\n");
   printf("3) If the snake gets big enough, food will spawn on top of it, I hope you can maneuver the snake well enough\n");
   printf("4) HIT ANY KEY TO START and then enter after\n");
   char hello[500];
   scanf("%s", hello);
   system("clear");

   bool isGameOverBorder = false; //boolean to check if snake hit border
   bool isCollision = false; //boolean to check if snake hit itself
   int oldX, oldY; //stores the previous location
   snake **body = malloc(sizeof(snake)*500); //the max snake size can be 500
   initialize(&food1, &snake1, map);

   while(isGameOverBorder == false && isCollision == false) {
       usleep(100000); //sleeps the program
       printf("\e[1;1H\e[2J"); //clears the screen ->i dont know how it does but it does
       keyHit(&snake1); //changes direction accordingly

       //set oldX and oldY
       oldX = snake1.x;
       oldY = snake1.y;
       moveSnake(&snake1, map);

       int i = 0; //counter
       int formerXOne =0; //the old position that is NOT the head
       int formerYOne =0;

       int formerXcur =0; //the current posittion
       int formerYcur =0;
       while(i < snake1.size-1){
           if(i == 0){
               //if the body is the one immediately after the head, it follows position of head

               map[body[0]->y][body[0]->x] = ' ';
               formerXOne = body[0]->x;
               formerYOne = body[0]->y;
               body[0]->x = oldX;
               body[0]->y = oldY;
               map[body[0]->y][body[0]->x] = '0';
           }
           else{
               //otherwise, the body will follow the one directly in front of it
               //since based off size, a new part will be added if snake grows

               map[body[i]->y][body[i]->x] = ' ';
               formerXcur = body[i]->x;
               formerYcur = body[i]->y;

               body[i]->x = formerXOne;
               body[i]->y = formerYOne;

               formerYOne = formerYcur;
               formerXOne = formerXcur;
               map[body[i]->y][body[i]->x] = '0';
           }
           i++;
       }

       //calling check food at the end allows us to have the one tester food at the beginning
       if(checkfood(&snake1,&food1, map)){
           body[snake1.size-1] = malloc(sizeof(snake));
           if(snake1.size-1 == 0){
               body[0]->x = oldX;
               body[0]->y = oldY;
               //This code creates a new body part of one directly following head
           }
       }

       draw(&food1, map);
       isGameOverBorder = checkOver(&snake1);

       //This checks to see if snake collided with iteself
       int j = 0;
       while (j < snake1.size){
           if(snake1.x == body[j]->x && snake1.y == body[j]->y){
               isCollision = true;
           }
           j++;
       }

   }
   free(body);
   system("clear");
   printf("GAME OVER!!\n");
   printf("(._. )( ._.)\n");
   printf("Your score was: %d\n",snake1.size);

   //this part reads and write to file to see if a new high score was recieved.
   int highscore;
   FILE* in = fopen("../Snake/highScore.txt", "r+");
   fscanf(in, "%d", &highscore);
   if(snake1.size >= highscore){
       fseek(in, 0, SEEK_SET);
       printf("congrats you have the new high score");
       fprintf(in, "%d", snake1.size);
   }
   else{
       printf("the high score is: %d", highscore);
   }
   fclose(in);
   printf("\n hit any key and then enter to exit");
   scanf("%s", hello);





   return 1;
}


//This code at the bottom is bunch of code that i kept trying but couldnt get to work

//So the way I am thinking, it to make a really big array using dynamic allocation, of like 500, with all
//of the values originally set to null and then initialize each index in the array as food is being eaten
//so it could be like body[size -1].x and so on and so forth
//       snake **body = malloc(sizeof(snake)*snake1.size);
//       int i =0;
//       while(i < snake1.size){
//           body[i] = malloc(sizeof(snake));
//           if(i == 0){
//               body[i]->x = oldX;
//               body[i]->y = oldY;
//           }
//           else{
//               //map[body[i]->y][body[i]->x] = ' ';
//               body[i]->x = body[i-1]->x;
//               body[i]->y = body[i-1]->y;
//               map[body[i]->y][body[i]->x] = '0';
//           }
//           moveSnake(body[i], map);
//           i++;
//       }
//       free(body);
// else{
//               if(snake1.direction == 1)//give coordinate of new
//           }

//        if(old == 3){
//            int i = 1;
//            while (i <= snake->size){
//                board[snake->y+i][snake->x] = ' ';
//                i++;
//            }
//        }
//        if(old ==2){
//            int i = 1;
//            while (i <= snake->size){
//                board[snake->y][snake->x+i] = ' ';
//                i++;
//            }
//        }
//        if(old == 4){
//            int i = 1;
//            while (i <= snake->size){
//                board[snake->y-i][snake->x] = ' ';
//                i++;
//            }
//        }
//    }


