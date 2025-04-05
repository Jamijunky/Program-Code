#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
  char username[CREDENTIAL_LENGTH];
  char password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user();
void fix_fgets_input(char *);
void input_credentials(char *username, char *password);
int main()
{
  int option;
  int user_index;
  while (1)
  {
    printf("----------------------------------------------------");
    printf("\nWelcome to User Management\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Select your option: ");
    scanf("%d", &option);
    getchar();

    switch (option)
    {
    case 1:
      register_user();
      break;
    case 2:
      user_index = login_user();
      if (user_index >= 0)
      {
        printf("\nLogin successful. Welcome %s\n", users[user_index].username);
      }
      else
      {
        printf("\nInvalid username or password. Please try again.\n");
      }
      break;
    case 3:
      printf("Exiting program\n");
      return 0;
      break;
    default:
      printf("Invalid option. Please try again.\n");
    }
  }

  return 0;
}

void register_user()
{
  if (user_count == MAX_USERS)
  {
    printf("Maximum user limit reached. Cannot register new user.\n");
    return;
  }
  int new_index = user_count;
  printf("\nRegister a new user\n");
  input_credentials(users[new_index].username, users[new_index].password);
  user_count++;
  printf("\nUser registered successfully\n");
}

int login_user()
{
  char username[CREDENTIAL_LENGTH];
  char password[CREDENTIAL_LENGTH];
  input_credentials(username, password);
  for (int i = 0; i < user_count; i++)
  {
    if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
    {
      return i;
    }
  }
  return -1;
}
void input_credentials(char *username, char *password)
{
  printf("\nEnter Username: ");
  fgets(username, CREDENTIAL_LENGTH, stdin);
  fix_fgets_input(username);
  printf("Enter Password(Masking Enabled): ");

  // change terminal properties
  struct termios old_props, new_props;
  tcgetattr(STDIN_FILENO, &old_props);
  new_props = old_props;
  new_props.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_props);

  char ch;
  int i = 0;
  while ((ch = getchar()) != '\n' && ch != EOF)
  {
    if (ch == '\b' || ch == 127)
    {
      if (i > 0)
      {
        printf("\b \b");
        i--;
      }
    }
    else
    {
      password[i++] = ch;
      printf("*");
    }
  }
  password[i] = '\0';
  tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
}

void fix_fgets_input(char *string)
{
  int index = strcspn(string, "\n");
  string[index] = '\0';
}
