/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
#define N 25
#define BOARD_ELEMENT '#'
#define PERCENT 0
#define FIRST_PLAYER PERCENT
#define PERCENT_HEAD '%'
#define SHTRODEL 1
#define SHTRODEL_HEAD '@'
#define ILLEGAL_MOVE 0

/*-------------------------------------------------------------------------
*   Function declartion
*--------------------------------------------------------------------------*/

void print_introduction_msg();                        //print welcome message , and introduction message to the game
void print_board_size_msg();                          //print message to enter board size
void print_steps_without_food();                      //print message to enter maximum number of steps can snake do without food
void print_food_location_msg();                       //print message to insert place for next food
void help_print_board(int size);                      //printing static part of the board
void print_board(char board[N][N], int size);          //print the current board for the user
void print_player_message(int player);                //print message when we switch between users
void print_insert_direction();			              //print message asking the user to insert his move
void print_finsih_msg(int player,int finish_reason ); //get the player who lose and the reason of losing and print message state
void print_error_input();                             //print message - there is error in the input
void print_invalid_input();			                  //print message - re-insert valid input
void print_full_board();		                      //print message - full board - no winner

int main()
{
  //add here you code
  return 0;
}

//add here your own function implementation.


void print_introduction_msg()
{
    printf("Welcome to multi-snake  game, The game have 2 player Percent and Shtrodel.\n"
    "The game starts with PERCENT player.\n");
    printf("You have to choose 4 moves :Up,Down,Right and Left "
    "The Percent player is the snake that starts in (0,0)\n\n");
}

void print_board_size_msg(){
    printf("Insert board size between 4 and 25:\n");
}

void print_steps_without_food(){
    printf("Insert the maximum number of steps the snake can do without food:\n");
}

void print_food_location_msg(){
    printf("in order to continue the game please Insert a row then column numbers to place the next food: \n");
}

void help_print_board(int size)
{
    int i=0;
    printf("%c",BOARD_ELEMENT);
    for(i=0;i<size;i++)
    {
        printf("%c",BOARD_ELEMENT);
    }
    printf("%c\n",BOARD_ELEMENT);
}

void print_board(char board[N][N], int size)
{
    int i=0,j=0;
    help_print_board(size);
    for(i=0;i<size;i++)
    {
        printf("%c",BOARD_ELEMENT);
        for(j=0;j<size;j++)
        {
            printf("%c",board[i][j]);
        }
        printf("%c\n",BOARD_ELEMENT);
    }
    help_print_board(size);
    printf("\n\n");
}

void print_player_message(int player )
{
    printf("******* Turn of %c ***********\n",player==PERCENT?PERCENT_HEAD:SHTRODEL_HEAD);
}

void print_insert_direction(){
    printf("Enter the direction to move your snake: (2-down,4-left,6-right,8-up):\n");
}

void print_finsih_msg(int player ,int finish_reason)
{
    printf("\nThe game finish and the winner is:\n");
    printf("*** %s player ****.\n",player==PERCENT?"SHTRODEL":"PERCENT");
    printf("The reason is %s of the ",finish_reason==ILLEGAL_MOVE? "Illegal move" : "Snake die");
    printf("%s player.\n\n",player==PERCENT?"PERCENT":"SHTRODEL");
}

void print_invalid_input(){
    printf("Please re-Inset valid input:\n");
}

void print_full_board(){
    printf("Full Board. The game over with no Winner.\n");
}
void print_error_input(){
    printf("Error with the input.\n");
}
