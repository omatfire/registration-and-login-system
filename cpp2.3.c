#include <stdio.h>
#include <stdlib.h>
int i,menu();
void reg();
void login();
void forgot();

struct account
{
    char first_name[20];
    char last_name[20];
    char username[30];
    char pass1[20];
};
void divider()
{
    for (i = 0; i < 50; i++)
    {
        printf("-");
    }
}
int main()
{
    while (1)
    {
        system("cls");
        switch (menu())
        {
        case 1:
            reg();
            break;

        case 2:
            login();
            break;
            
        case 3:
            forgot();
            break;    

        case 4:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}

int menu()
{
    int c;
    printf("\n------WELCOME TO MAIN MENU--------\n");
    divider();
    printf("\n1.REGISTER\n");
    printf("2.LOGIN\n");
    printf("3.FORGOT CREDENTIALS\n");
    printf("4.EXIT\n");
    divider();
    printf("\nEnter your choice : ");
    scanf("%d", &c);
    return c;
}

void takepassword(char pass[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }
}

void reg()
{
    struct account u;
    system("cls");
    char pass2[20];
    printf("REGISTERATION \n");
    divider();
    printf("\nENTER your first name : ");
    scanf("%s", u.first_name);
    printf("Enter last name : ");
    scanf("%s", u.last_name);
    printf("Enter your username : ");
    scanf("%s", u.username);
    printf("Enter password : ");
    takepassword(u.pass1);

conf_pass:
    printf("\nConfirm password : ");
    scanf("%s", pass2);

    if (strcmp(u.pass1, pass2))
    {
        printf("INCORRECT PASSWORD \n\n");
        goto conf_pass;
    }
    else
    {
        printf("ACCOUNT CREATED SUCCESSFULLY\n\n");
        getch();

        FILE *fp = fopen("account.txt", "w");
        fwrite(&u, sizeof(struct account), 1, fp);
        fclose(fp);
    }
}

void login()
{
    system("cls");
    char user[30], log_pass[20];

    struct account u;
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(struct account), 1, fp);

name:
    printf("enter Username : ");
    scanf("%s", user);
    if (strcmp(u.username, user))
    {
        printf("\nPLEASE ENTER CORRECT USERNAME\n ");
        goto name;
    }

    else
    {
    logpass:
        printf("Enter password : ");
        takepassword(log_pass);
        if (strcmp(u.pass1, log_pass))
        {
            printf("\nINCORRET PASSWORD \n");
            goto logpass;
        }
        else
        {
            system("cls");
            printf("\n************WELCOME %s************\n", u.first_name);
            divider();

            printf("\nYour Details \n");
            divider();
            printf("\nUsername     : %s\n", u.username);
            printf("first name   : %s\n", u.first_name);
            printf("Last name    : %s\n", u.last_name);
            printf("Password     : %s\n", u.pass1);
        }
        getch();
    }
    fclose(fp);
}

void forgot()
{
    system("cls");
    struct account u;
    int choice;
    char username[20], password[20];
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(struct account), 1, fp);

    printf("\n1.Search by Username\n");
    printf("2.Search by password\n");
    printf("4.main menu\n");
    divider();
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter your Username : ");
        scanf("%s", username);
        if (strcmp(username, u.username))
        {
            printf("USERNAME NOT FOUND !!");
            getch();
        }
        else
        {
            printf("ACCOUNT FOUND!\n");
            divider();
            printf("\nUsername    : %s \n", u.username);
            printf("First name  : %s \n", u.first_name);
            printf("Last name   : %s \n", u.last_name);
            printf("Password    : %s \n", u.pass1);
            getch();
        }

        break;

    case 2:
        printf("Enter your Passowrd : ");
        scanf("%s", password);
        if (strcmp(password, u.pass1))
        {
            printf("ACCOUNT NOT FOUND !!");
            getch();
        }
        else
        {
            printf("ACCOUNT FOUND!\n");
            divider();
            printf("\nUsername    : %s \n", u.username);
            printf("First name  : %s \n", u.first_name);
            printf("Last name   : %s \n", u.last_name);
            printf("Password    : %s \n", u.pass1);
            getch();
        }

        break;
    
    case3:
        return;

    default:
        printf("INVALID CHOICE\n");
        break;
    }

    fclose(fp);
}


