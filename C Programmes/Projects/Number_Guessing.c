#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int guess, random;
  int no_of_attempts = 0;
  srand(time(NULL));
way_up:
  printf("Welcome to the game of number guessing\n");
  printf("guess the number between 1 to 100\n");
  printf("Your first guess is:");
  random = rand() % 100 + 1; // generate a random number between 1 and 100
  do
  {

    scanf("%d", &guess);
    no_of_attempts++;

    if (guess > random)
    {
      printf("guess a lower number:");
    }
    else if (guess < random)
    {
      printf("guess a higher number:");
    }
    else
    {
      printf("Congratulations, you guessed the number in %d attempts\n", no_of_attempts);
    }
  } while (guess != random);

up:
  printf("Do you wan to play again?\nIf yes then enter 1, if no then enter 0\n");
  int play_again;
  scanf("%d", &play_again);
  if (play_again == 1)
  {
    goto way_up;
  }
  else if (play_again == 0)

  {
    printf("Thanks for playing\n");
    printf("Developed By: Abdullah Jami\n");
  }
  else
  {
    printf("Invalid input,Try again");
    goto up;
  }

  return 0;
}