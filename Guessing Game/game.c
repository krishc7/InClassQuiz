#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main() {

    // Declare variables to hold various data points
    int input, number, guess;
    int temp = 0;
    int tries = 0;
    int won = 0;
    int lost = 0;
    int max = 10;
    char x;

    srand(time(NULL));

    FILE *fp;

    // Loop while Quit (option 3) is not chosen
    do {

        printf("\nWelcome to the game, please choose an option.");
        printf("\nPress 1 to Play a Game");
        printf("\nPress 2 to change the max number");
        printf("\nPress 3 to quit\n");
        scanf("\n%d", &input);

        if (input == 1) {
            number = (rand() % (max)) + 1;
            // Loop executes as long as correct number is not guessed
            do {
            printf("\nPlease guess a number. ");
            scanf("%49s", &x);
            guess = x - '0';
            temp++;

            // If user inputs 'q', quit the current game and mark ass loss
            if(x == 'q') {
                lost++;
                tries = 0;
                break;
            }
            else if(guess > number) {
                printf("Too high! Guess again. \n\n");
            }
            else if(guess < number) {
                printf("Too low!\n\n");
            }
            // If guess is not too high or too low, it is correct
            else {
                printf("\nCorrect!\n");
                won++;
                tries += temp;
                tries = 0;
                break;
                }
            } while((guess != number));
        }

        if (input == 2) {
            // Ask user for max value until one in valid range is given
            do {
            printf("\nThe max value you can set is %d and max value cannot be negative.", INT_MAX);
            printf("\nPlease enter a new maximum value. ");
            scanf("%d", &max);
            } while(max > INT_MAX || max < 0);
        }

    } while(input != 3);

    printf("\nThank you for playing!");
    printf("\nTotal number of wins: %d", won);
    printf("\nTotal number of losses: %d", lost);
    printf("\nNumber of guesses taken to win: %d", tries);

    return 0;
}
