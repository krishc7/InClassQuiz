#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // Create variables to store various data
    float tax, tip, meal;
    char *name;

    // Convert command line arguments from type char to floating point, as percentage
    tax = (atof(argv[1]));
    tip = (atof(argv[2]));

    // Integer option will hold a random number between 1 to 4
    srand(time(NULL));
    int option = (rand() % 4) + 1;
    

    // Switch case to choose a meal at random
    switch(option) {
        case 1 :
            meal = 9.95;
            name = "Salad";
            break;
        case 2 :
            meal = 4.55;
            name = "Soup";
            break;
        case 3 :
            meal = 13.25;
            name = "Sandwich";
            break;
        case 4 : 
            meal = 22.35;
            name = "Pizza";
            break;
    }
    // Calculate the tip and tax amount
    float taxAmt = (meal * tax)/100.0;
    float tipAmt = (meal * tip)/100.0;

    // Print program output
    printf("\nMeal: %s($%.2f)", name, meal);
    printf("\nTax: %.2f%% ", tax);
    printf("\nTip: %.2f%%", tip);
    printf("\nTotal: $%.2f", (meal + taxAmt + tipAmt));

    return 0;
}