
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 25
#define BOARD_ELEMENT '#'
#define PERCENT 0
#define FIRST_PLAYER PERCENT
#define PERCENT_HEAD '%'
#define SHTRODEL 1
#define SHTRODEL_HEAD '@'
#define ILLEGAL_MOVE 0
#define SNAKE_DIE 1
#define LEGAL_MOVE 1
#define MIN_STEPS 1
#define ONE_INPUT 1
#define TWO_INPUTS 2
#define MIN_SIZE 4
#define MAX_SIZE 25
#define PERCENT_BODY '*'
#define SHTRODEL_BODY '+'
#define FOOD 'F'
#define YES 1
#define NO 0
#define UP 8
#define LEFT 4
#define RIGHT 6
#define DOWN 2
#define EMPTY ' '
#define START_LENGTH 3
#define PLAYER 0
#define PERCENT_SIZE 1
#define SHTRODEL_SIZE 2
#define COUNTER_STEPS_PERCENT 3
#define COUNTER_STEPS_SHTRODEL 4
#define HUNGER 5
#define KEEP_PLAYING 6
#define ATE_FOOD 1
#define NOT_ATE_FOOD 0

void print_introduction_msg();
//print welcome message , and introduction message to the game
void print_board_size_msg();
//print message to enter board size
int insert_board_size();
//insert the size of the board and check if the input is valid
void test_input(int scan_test,int scan_size);
//check that there is no error in the input
void print_invalid_input();
//print message - re-insert valid input
void print_error_input();
//print message - there is error in the input
void print_steps_without_food();
//print message to enter maximum number of steps can snake do without food
int insert_steps_without_food();
//get maximum number of steps that each player can do without food
//and check that the input is valid
void initialize_board(char board[N][N],int size,int snake_percent[],
                      int snake_shtrodel[]);
//initialize the board to be empty and place the snakes on board
void help_initialize_board(char board[N][N],int size);
//initialize static characters
void print_food_location_msg();
//print message to insert place for next food
void insert_food_location(int size,char board[N][N]);
//place the food on the board in a valid place
void help_print_board(int size);
//printing static part of the board
void print_board(char board[N][N], int size);
//print the current board for the user
void play_game(char board[N][N],int size,int snake_percent[],int max_steps,
               int snake_shtrodel[]);
//start play the game and stop while there is reason to finish
void initialize_info(int info[]);
//save the size of the snakes, number of moves without food,
//if there is reason for keep playing, and current player
void game_turn(char board[N][N],int size,int snake[],int info[],
               int max_steps);
//get the direction and move the snake according to the rules
void print_player_message(int player);
 //print message when we switch between users
void print_insert_direction();
//print message asking the user to insert his move
int insert_direction();
//current player put the direction to move the snake
void check_valid_direction(int direction,int info[],int size,int snake[]);
//check if the direction is inside the board
void check_snake_ate(char board[N][N],int snake[],int direction,
              int size,int info[]);
//check if the snake ate food in the direction that has been chosen
void grow_snake(char board[N][N],int snake[],int direction,
              int size,int info[]);
//move the snake to the direction that has been chosen
//and grow up the body by one body
void keep_playing_if_not_ate(char board[N][N],int direction,int snake[]
                             ,int info[],int size);
//move to snake if the snake don't eat food
void check_legal_move(char board[N][N],int direction,int snake[],
                int info[]);
//check if the snake can move to the direction that has been chosen
void illegal_move(int info[]);
//stop playing and return message illegal move
void move_the_snake(int size,int direction,int snake[]);
//move the snake to the direction that has been chosen
void move_the_snake_down(int size,int snake[]);
//move the head of the snake down and shift the body one place ahead
void move_the_snake_left(int size,int snake[]);
//move the head of the snake left and shift the body one place ahead
void move_the_snake_right(int size,int snake[]);
//move the head of the snake right and shift the body one place ahead
void move_the_snake_up(int size,int snake[]);
//move the head of the snake up and shift the body one place ahead
void print_board_after_move(char board[N][N],int snake[],
    int info[],int size);
//after saving the new place of the snake the board print
//the current place of the snake
void print_precent(char board[N][N],int snake[],int info[]);
//print the precent snake after move on the board
void print_precent_after_food(char board[N][N],int snake[],
    int info[]);
//print the precent snake after move on the board if ate
void print_shtrodel(char board[N][N],int snake[],int info[]);
//print the shtrodel snake after move on the board
void print_shtrodel_after_food(char board[N][N],int snake[],
    int info[]);
//print the shtrodel snake after move on the board if ate
void print_finish_msg(int player,int finish_reason );
//get the player who lose and the reason of losing and print message state
void check_snake_die(int info[],int max_steps);
//if the snake reached max number of steps without eating
void check_full_board(char board[N][N],int size,int info[],int snake[],int direction);
//check if the board is full
void print_full_board();
//print message - full board - no winner




int main(){
//function lenght:13
    print_introduction_msg();
    print_board_size_msg();
    int size=insert_board_size();
    print_steps_without_food();
    int max_steps=insert_steps_without_food();
    print_food_location_msg();
    char board[N][N];
    int snake_percent[N*N]={0},snake_shtrodel[N*N]={0}; ;
    //save the location of the snake
    initialize_board(board,size,snake_percent,snake_shtrodel);
    insert_food_location(size,board);
    print_board(board,size);
    play_game(board,size,snake_percent,max_steps,snake_shtrodel);
    return 0;
}

void print_introduction_msg(){
//function lenght: 2
    printf("Welcome to multi-snake  game, The game have "
           "2 player Percent and Shtrodel.\n"
    "The game starts with PERCENT player.\n");
    printf("You have to choose 4 moves :Up,Down,Right and Left "
    "The Percent player is the snake that starts in (0,0)\n\n");
}

void print_board_size_msg(){
//function lenght:1
    printf("Insert board size between 4 and 25:\n");
}

int insert_board_size(){
//function lenght:8
    int size=0;
    int scan_test=scanf("%d",&size);
    test_input(scan_test,ONE_INPUT);
    while(size<MIN_SIZE || size>MAX_SIZE){
        print_invalid_input();
        scan_test=scanf("%d",&size);
        test_input(scan_test,ONE_INPUT);
    }
    return size;
}

void test_input(int scan_test,int scan_size){
//function lenght:3
    if(scan_test<scan_size){
            print_error_input();
            exit(YES);
    }
}

void print_error_input(){
//function lenght:1
    printf("Error with the input.\n");
}

void print_invalid_input(){
//function lenght:1
    printf("Please re-Inset valid input:\n");
}

void print_steps_without_food(){
//function lenght:1
    printf("Insert the maximum number of steps the snake "
           "can do without food:\n");
}

int insert_steps_without_food(){
//function lenght:8
    int steps=0;
    int scan_test=scanf("%d",&steps);
    test_input(scan_test,ONE_INPUT);
    while(steps<=MIN_STEPS){
        print_invalid_input();
        scan_test=scanf("%d",&steps);
        test_input(scan_test,ONE_INPUT);
    }
    return steps;
}

void initialize_board(char board[N][N],int size,int snake_percent[],
                      int snake_shtrodel[]){
//function lenght:12
    int row=0,column=0;
    //shtrodel place is depend on the size of the board
    for(int i=0;i<3;i++){
        row=i*2;
        column=i*2+1;
        snake_shtrodel[row]=size-1;
        snake_shtrodel[column]=i;
        snake_percent[row]=0;
        snake_percent[column]=i;
    }
    for(row=0;row<size;row++){
        for(column=0;column<size;column++){
            board[row][column]=EMPTY;
        }
    }
    help_initialize_board(board,size);
}

void help_initialize_board(char board[N][N],int size){
//function lenght:6
//initialize static characters
    board[0][0]=PERCENT_HEAD;
    board[0][1]=PERCENT_BODY;
    board[0][2]=PERCENT_BODY;
    board[size-1][0]=SHTRODEL_HEAD;
    board[size-1][1]=SHTRODEL_BODY;
    board[size-1][2]=SHTRODEL_BODY;
}

void print_food_location_msg(){
//function lenght:1
    printf("in order to continue the game please Insert a row "
           "then column numbers to place the next food: \n");
}

void insert_food_location(int size,char board[N][N]){
//function lenght:8
    int row=0,column=0;
    int scan_test=scanf("%d %d",&row,&column);
    test_input(scan_test,TWO_INPUTS);
    //check if the input is not on a snake and between the borders
    while(row>=size || row<0 || (board[row][column])!=EMPTY ||
        column>=size || column<0){
        print_invalid_input();
        scan_test=scanf("%d %d",&row,&column);
        test_input(scan_test,TWO_INPUTS);
    }
    //place the food in the board
    board[row][column]=FOOD;
}

void help_print_board(int size){
//function lenght:5
    int i=0;
    printf("%c",BOARD_ELEMENT);
    for(i=0;i<size;i++)
    {
        printf("%c",BOARD_ELEMENT);
    }
    printf("%c\n",BOARD_ELEMENT);
}

void print_board(char board[N][N], int size)
{//function lenght:9
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

void play_game(char board[N][N],int size,int snake_percent[],
               int max_steps,int snake_shtrodel[]){
//function lenght:10
//play the game, change players after turn and check that
//there is no reason to finish, if there is a reason he finish the game
    int info[7]={0};
    initialize_info(info);
    while(info[KEEP_PLAYING]){
        if(info[PLAYER]==PERCENT){
            info[COUNTER_STEPS_PERCENT]++;
            game_turn(board,size,snake_percent,info,max_steps);
            info[PLAYER]=SHTRODEL;
        }
        if(info[PLAYER]==SHTRODEL && (info[KEEP_PLAYING])){
            info[COUNTER_STEPS_SHTRODEL]++;
            game_turn(board,size,snake_shtrodel,info,max_steps);
            info[PLAYER]=PERCENT;
        }
    }
}

void initialize_info(int info[]){
//function lenght:7
    info[PLAYER]=PERCENT;
    info[PERCENT_SIZE]=START_LENGTH;
    info[SHTRODEL_SIZE]=START_LENGTH;
    info[COUNTER_STEPS_PERCENT]=0;
    info[COUNTER_STEPS_SHTRODEL]=0;
    info[HUNGER]=NOT_ATE_FOOD;
    info[KEEP_PLAYING]=YES;
}

void game_turn(char board[N][N],int size,int snake[],
              int info[],int max_steps){
//function lenght:13
    int direction=0;
    print_player_message(info[PLAYER]);
    print_insert_direction();
    direction=insert_direction();
    check_full_board(board,size,info,snake,direction);
    check_snake_die(info,max_steps);
    if(info[KEEP_PLAYING]){
        check_valid_direction(direction,info,size,snake);
        if(info[KEEP_PLAYING]){
            check_snake_ate(board,snake,direction,size,info);
            //if the snake ate he keep playing
            if((info[HUNGER])==NOT_ATE_FOOD){
                keep_playing_if_not_ate(board,direction,snake,info,size);
            }
        }
    }
    //after turn initialize hunger
    info[HUNGER]=NOT_ATE_FOOD;
}

void print_player_message(int player )
{//function lenght:1
    printf("******* Turn of %c ***********\n",
           player==PERCENT?PERCENT_HEAD:SHTRODEL_HEAD);
}

void print_insert_direction(){
//function lenght:1
    printf("Enter the direction to move your snake: "
            "(2-down,4-left,6-right,8-up):\n");
}

int insert_direction(){
//function lenght:8
        int direction=0;
        int scan_test=scanf("%d",&direction);
        test_input(scan_test,ONE_INPUT);
        while(direction!=UP && direction!=RIGHT && direction!=LEFT &&
               direction!=DOWN){
            print_invalid_input();
            scan_test=scanf("%d",&direction);
            test_input(scan_test,ONE_INPUT);
        }
        return direction;
}

void check_valid_direction(int direction,int info[],int size,int snake[]){
//function lenght:13
    switch(direction){
            case DOWN: if(snake[0]==(size-1)){
                        illegal_move(info);
                    }
                    break;
            case LEFT: if(snake[1]==0){
                        illegal_move(info);
                    }
                    break;
            case RIGHT: if(snake[1]==(size-1)){
                        illegal_move(info);
                    }
                    break;
            case UP: if(snake[0]==0){
                        illegal_move(info);
                    }
                    break;
        }
}

void check_snake_ate(char board[N][N],int snake[],int direction,
              int size,int info[]){
//function lenght:13
    switch(direction){
            case DOWN: if(board[snake[0]+1][snake[1]]==FOOD){
                            grow_snake(board,snake,direction
                                       ,size,info);
                        }
                        break;
            case LEFT: if(board[snake[0]][snake[1]-1]==FOOD){
                            grow_snake(board,snake,direction
                                       ,size,info);
                        }
                        break;
            case RIGHT: if(board[snake[0]][snake[1]+1]==FOOD){
                            grow_snake(board,snake,direction
                                       ,size,info);
                        }
                        break;
            case UP: if(board[snake[0]-1][snake[1]]==FOOD){
                            grow_snake(board,snake,direction
                                       ,size,info);
                        }
                        break;
    }
}

void grow_snake(char board[N][N],int snake[],int direction,
              int size,int info[]){
//function lenght:11
    if(info[KEEP_PLAYING]){
        print_food_location_msg();
        insert_food_location(size,board);
    }
    move_the_snake(size,direction,snake);
    if(info[PLAYER]==PERCENT){
        info[PERCENT_SIZE]++;
        info[COUNTER_STEPS_PERCENT]=0;
    }
    else{
        info[SHTRODEL_SIZE]++;
        info[COUNTER_STEPS_SHTRODEL]=0;
    }
    info[HUNGER]=ATE_FOOD;
    print_board_after_move(board,snake,info,size);
}

void keep_playing_if_not_ate(char board[N][N],int direction,int snake[]
                             ,int info[],int size){
//function lenght:4
    check_legal_move(board,direction,snake,info);
    if(info[KEEP_PLAYING]){
        move_the_snake(size,direction,snake);
        print_board_after_move(board,snake,info,size);
    }
}

void check_legal_move(char board[N][N],int direction,int snake[],
                      int info[]){
//function lenght:13
        switch(direction){
        //if the snake go to place that not free stop playing
            case DOWN: if(board[snake[0]+1][snake[1]]!=EMPTY &&
                          board[snake[0]+1][snake[1]]!=FOOD){
                            illegal_move(info);
                        }
                        break;
            case LEFT: if(board[snake[0]][snake[1]-1]!=EMPTY &&
                          board[snake[0]][snake[1]-1]!=FOOD){
                            illegal_move(info);
                        }
                        break;
            case RIGHT: if(board[snake[0]][snake[1]+1]!=EMPTY
                           && board[snake[0]][snake[1]+1]!=FOOD){
                            illegal_move(info);
                        }
                        break;
            case UP: if(board[snake[0]-1][snake[1]]!=EMPTY &&
                        board[snake[0]-1][snake[1]]!=FOOD){
                            illegal_move(info);
                        }
                        break;
        }
}

void illegal_move(int info[]){
//function lenght:2
    print_finish_msg(info[PLAYER],ILLEGAL_MOVE);
    info[KEEP_PLAYING]=NO;
}

void move_the_snake(int size,int direction,int snake[]){
//function lenght:9
        switch(direction){
            case DOWN: move_the_snake_down(size,snake);
                    break;
            case LEFT: move_the_snake_left(size,snake);
                    break;
            case RIGHT: move_the_snake_right(size,snake);
                    break;
            case UP: move_the_snake_up(size,snake);
                    break;
        }
}

void move_the_snake_down(int size,int snake[]){
//function lenght:3
        for(int i=((size*size)-1);i>1;i--){
            snake[i]=snake[i-2];
        }
        //move just row head place
        snake[0]++;
}

void move_the_snake_left(int size,int snake[]){
//function lenght:3
        for(int i=((size*size)-1);i>1;i--){
            snake[i]=snake[i-2];
        }
        //move just column head place
        snake[1]--;
}

void move_the_snake_right(int size,int snake[]){
//function lenght:3
        for(int i=((size*size)-1);i>1;i--){
            snake[i]=snake[i-2];
        }
        //move just column head place
        snake[1]++;
}

void move_the_snake_up(int size,int snake[]){
//function lenght:3
        for(int i=((size*size)-1);i>1;i--){
            snake[i]=snake[i-2];
        }
        //move just row head place
        snake[0]--;
}

void print_board_after_move(char board[N][N],int snake[],
    int info[],int size){
//function lenght:8
    if(info[PLAYER]==PERCENT){
        if(info[HUNGER]==ATE_FOOD){
            print_precent_after_food(board,snake,info);
        }
        else{
            print_precent(board,snake,info);
        }
    }
    else{
        if(info[HUNGER]==ATE_FOOD){
            print_shtrodel_after_food(board,snake,info);
        }
        else{
            print_shtrodel(board,snake,info);
        }
    }
    print_board(board,size);
}

void print_precent(char board[N][N],int snake[],
    int info[]){
//function lenght:6
    int i=0;
    //move the body of the snake
    //the place of the column saved on odd places of the array
    for(i=1;i<info[PERCENT_SIZE];i++){
        //row=snake[2*i];
        //column=snake[2*i+1];
        board[snake[2*i]][snake[2*i+1]]=PERCENT_BODY;
    }
    //tile row=snake[2*info[PERCENT_SIZE]];
    //tile column=snake[2*info[PERCENT_SIZE]+1];
    //delete the tile if not ate and place the head of the snake
    board[snake[2*info[PERCENT_SIZE]]][snake[2*info[PERCENT_SIZE]+1]]=
    EMPTY;
    board[snake[0]][snake[1]]=PERCENT_HEAD;
}

void print_precent_after_food(char board[N][N],int snake[],
    int info[]){
//function lenght:4
    int i=0;
    //move the body of the snake but not delete the tile
    //the place of the column saved on odd places of the array
    for(i=1;i<info[PERCENT_SIZE];i++){
        //row=snake[2*i];
        //column=snake[2*i+1];
        board[snake[2*i]][snake[2*i+1]]=PERCENT_BODY;
    }
    board[snake[0]][snake[1]]=PERCENT_HEAD;
}

void print_shtrodel(char board[N][N],int snake[],
    int info[]){
//function lenght:4
    //move the body of the snake
    for(int i=1;i<info[SHTRODEL_SIZE];i++){
        //row=snake[2*i];
        //column=snake[2*i+1];
        board[snake[2*i]][snake[2*i+1]]=SHTRODEL_BODY;
    }
    //tile row=snake[2*info[SHTRODEL_SIZE]];
    //tile column=snake[2*info[SHTRODEL_SIZE]+1];
    //delete the tile if not ate and place the head  of the snake
    board[snake[2*info[SHTRODEL_SIZE]]][snake[2*info[SHTRODEL_SIZE]+1]]=
    EMPTY;
    board[snake[0]][snake[1]]=SHTRODEL_HEAD;
}

void print_shtrodel_after_food(char board[N][N],int snake[],
    int info[]){
//function lenght:4
    int i=0;
    //move the body of the snake but not delete the tile
    //the place of the column saved on odd places of the array
    for(i=1;i<info[SHTRODEL_SIZE];i++){
        //row=snake[2*i];
        //column=snake[2*i+1];
        board[snake[2*i]][snake[2*i+1]]=SHTRODEL_BODY;
    }
    board[snake[0]][snake[1]]=SHTRODEL_HEAD;
}

void print_finish_msg(int player ,int finish_reason)
{//function lenght:4
    printf("\nThe game finish and the winner is:\n");
    printf("*** %s player ****.\n",player==PERCENT?"SHTRODEL":"PERCENT");
    printf("The reason is %s of the ",
           finish_reason==ILLEGAL_MOVE? "Illegal move" : "Snake die");
    printf("%s player.\n\n",player==PERCENT?"PERCENT":"SHTRODEL");
}

void check_snake_die(int info[],int max_steps){
//function lenght:3
    if(info[COUNTER_STEPS_PERCENT]==max_steps ||
        info[COUNTER_STEPS_SHTRODEL]==max_steps){
        print_finish_msg(info[PLAYER],SNAKE_DIE);
        info[KEEP_PLAYING]=NO;
    }
}

void check_full_board(char board[N][N],int size,int info[],
                      int snake[],int direction){
//function lenght:9
//check number of free places on the board
    int counter_full_place=1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]!=EMPTY && board[i][j]!=FOOD){
                counter_full_place++;
            }
        }
    }
    //stop playing if the board is full
    if(counter_full_place==(size*size)){
        info[KEEP_PLAYING]=NO;
        check_snake_ate(board,snake,direction,size,info);
        print_full_board();
    }
}

void print_full_board(){
//function lenght:1
    printf("Full Board. The game over with no Winner.\n");
}

