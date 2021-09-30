/*
    Create struct for a meal that consists of price and name
    add array of meals
    randomly generate values 0-3 to determine the meal chosen
    ask user to input tax and tip 
    calculate total bill and print values
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct Meal
{
    char name[100];
    double price;
};

int main(){
    struct Meal salad;
    struct Meal soup;
    struct Meal sandwich;
    struct Meal pizza;

    strcpy(salad.name, "Salad");
    strcpy(soup.name, "Soup");
    strcpy(sandwich.name, "Sandwich");
    strcpy(pizza.name, "Pizza");

    salad.price = 9.95;
    soup.price = 4.55;
    sandwich.price = 13.25;
    pizza.price = 22.35;

    struct Meal meals[4];
    meals[0] = salad;
    meals[1] = soup;
    meals[2] = sandwich;
    meals[3] = pizza;

    int rngV;
    srand(time(NULL));
    rngV = (rand() % 4);

    int tax;
    int tip;
    printf("Enter a tax and tip amount: ");
    scanf("%d%d", &tax, &tip);

    printf("%s : $%.2f",meals[rngV].name, meals[rngV].price);

    double mealCost = meals[rngV].price;
    double tipAmount = (double) tip /100 * mealCost;
    double taxAmount = (double) tax /100 * mealCost;

    double totalCost = mealCost + tipAmount + taxAmount;

    //printf("\nMeal Cost: %.2f", mealCost);
    printf("\nTip Cost: $%.2f", tipAmount);
    printf("\nTax Cost: $%.2f", taxAmount);
    printf("\nTotal Cost: $%.2f", totalCost);

}
