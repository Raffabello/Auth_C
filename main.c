#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CLI_COMMAND_BUFFER_SIZE 256
#define CLI_SYMBOL "Ringi Auth>"
#define FILE_NAME "user.json"

#define PASSWORD_LEN 12
#define COMMAND_LEN 12

void generate_rnd_pwd(void);
void show_content(FILE * fl);

int main(void)
{
    srand(time(NULL));

    char command_str[CLI_COMMAND_BUFFER_SIZE];
    char command[COMMAND_LEN];
    char throwaway;
    FILE *user_file = fopen(FILE_NAME, "r");
    if(user_file == NULL)
    {
        printf("The file user.json does not exist! Place the file into the server_engine/auth folder!\nPress any key to quit.");
        scanf("%c", &throwaway);
        return 1;
    }
    else
    {
        fclose(user_file);
        fopen(FILE_NAME, "r+");
        printf("Ringi System auth process \n");
        do
        {
            printf(CLI_SYMBOL);
            scanf(" %[^\n]", command_str);

            if(strcmp(command_str, "/show users") == 0)
                show_content(user_file);

        }while(strcmp(command_str, "/quit") != 0);

    }
    return 0;
}

void generate_rnd_pwd(void)
{
    char rnd_password[PASSWORD_LEN + 1];
    for(int i = 0; i < PASSWORD_LEN; i++)
    {    
        rnd_password[i] = (char) (33 + rand() % (122 - 33 + 1));
    }    
    rnd_password[PASSWORD_LEN] = '\0';
    printf("%s\n", rnd_password);
}

void show_content(FILE *fl)
{
    int character;

    while((character = fgetc(fl)) != EOF)
    {
        printf("%c", character);
    }
    printf("\n");
}