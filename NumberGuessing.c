/*
    create a function that will call the menu and wait for user to input value
    create a function that is game state that loops and chooses randomnumbers based on the max number
    create a function that will allow user to change max number
    call menu from main
*/
#include <stdio.h>
#include <stdlib.h>
static int maxNum = 10;
typedef char guessing;
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
            printf("Enter a positive Value!\n");
    }
    getMenu();
}

void playGame(){
    printf("the max is %d\n", maxNum);
    int guessed = 0;
    guessing c;

    int randV = 1;
    srand(time(NULL));
    randV = ( rand() % maxNum) + 1;

    printf("DEBUG: %d\n", randV);

    while(guessed != randV){
        printf("\nMake your guess: ");
        c = getchar();

        printf("YOU GUESSED: ");
        putchar(c);

        guessed = atoi(c);
        if(guessed == randV)
            break;
        else if(guessed > randV)
            printf("Too high!\n");
        else
            printf("Too Low!\n");
    }

    printf("\nYou win!\n");
    getMenu();
}