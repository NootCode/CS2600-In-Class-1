/*
    create a function that will call the menu and wait for user to input value
    create a function that is game state that loops and chooses randomnumbers based on the max number
    create a function that will allow user to change max number
    call menu from main
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

static int maxNum = 10;
void main(){
    getMenu();

    return 0;
}

void getMenu(){
    printf("Press 1 to play a game\n");
    printf("Press 2 to change max number\n");
    printf("Press 3 to quit\n");

    int pressed;
    scanf("%d", &pressed);
    if(pressed == 1)
        playGame();
    if(pressed == 2)
        changeMax();
    if(pressed == 3)
        endGame();
    
}

void endGame(){
    printf("Thanks for Playing!");
}

void changeMax(){
    int check = 0;
    while(check == 0){
        printf("What would you like the max to be? ");
        scanf("%d", &maxNum);
        if(maxNum > 0)
            check = 1;
        else
            printf("Enter a positive Value!");
    }
    getMenu();
}

void playGame(){
    int guessed = 0;
    int randV = 1;
    int win = 0;
    char quit;
    srand(time(NULL));
    randV = ( rand() % maxNum) + 1;
    while(guessed != rand){
        printf("\nMake your guess from 1 - %d: ", maxNum);
        scanf("%d", &guessed);
        printf("You guessed: %d\n", (int)guessed);
        if(guessed == randV)
            break;
        else if(guessed > randV)
            printf("Too high!\n");
        else if(guessed < randV)
            printf("Too Low!\n");
        printf("Enter q to quit: ");
        scanf("%s", &quit);

        if(quit == 'q'){
            win = 1;
            break;
        }
    }
    if(win == 0)
        printf("\nYou win!\n");
    else
        printf("\nTry Again Next Time\n");

    getMenu();
}