#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit()

// signup
char fullname_list[200];
char username_list[200];
char date_of_birth_list[100];
char email_list[200];
long long mobile_number_list;
char gender_list[10];
char country_list[200];
char confirm_password_list[200];
char term_conditions_list[20];

// login
char name_list[100];
char password_list[100];

int bus_reservation_system()
{
    int number;
    printf("\n\t******** BUS RESERVATION ********\t");
    printf("\nPress 1. For Sign up ");
    printf("\nPress 2. For Login ");
    printf("\nPress 3. For Exit \n");
    printf("Please enter any number: ");
    scanf("%d", &number);
    return number;
}

int signup()
{
    FILE *fp;

    printf("\nPlease Enter Full Name: ");
    scanf(" %[^\n]", fullname_list);

    printf("\nPlease Enter Username: ");
    scanf(" %[^\n]", username_list);

    printf("\nPlease Enter Date_of_Birth: ");
    scanf(" %[^\n]", date_of_birth_list);

    printf("\nPlease Enter Email ID: ");
    scanf(" %[^\n]", email_list);

    printf("\nPlease Enter Mobile Number: ");
    scanf("%lld", &mobile_number_list);

    printf("\nPlease Enter Gender: ");
    scanf(" %[^\n]", gender_list);

    printf("\nPlease Enter Country: ");
    scanf(" %[^\n]", country_list);

    printf("\nPlease Enter Confirm Password: ");
    scanf(" %[^\n]", confirm_password_list);

    // Terms & Conditions check
    while (1)
    {
        printf("\nPlease Enter Terms & Conditions (Yes/No): ");
        scanf(" %[^\n]", term_conditions_list);

        if (strcmp(term_conditions_list, "yes") == 0 || strcmp(term_conditions_list, "YES") == 0)
        {
            //Data save in file(overwrite)
            fp = fopen("user_data.txt", "w");
            if (fp == NULL)
            {
                printf("\nError saving data\n");
                return 0;
            }
            fprintf(fp, "%s\n", username_list);
            fprintf(fp, "%s\n", confirm_password_list);
            fprintf(fp, "%s\n", fullname_list);
            fclose(fp);

            printf("\nSignup Complete. Congratulations %s!\n", fullname_list);
            return 1;
        }
        else if (strcmp(term_conditions_list, "no") == 0 || strcmp(term_conditions_list, "NO") == 0)
        {
            printf("\nYou must accept Terms & Conditions to complete signup.\n");
        }
        else
        {
            printf("\nInvalid input! Please type Yes or No only.\n");
        }
    }
}

int login()
{
    FILE *fp;
    char file_username[200], file_password[200], file_fullname[200];
    
    //read file data
    fp = fopen("user_data.txt", "r");
    if (fp == NULL)
    {
        printf("\nNo user data found. Please sign uo first.\n");
        return 0;
    }

    fgets(file_username, sizeof(file_username), fp);
    file_username[strcspn(file_username, "\n")] = '\0';

    fgets(file_password, sizeof(file_password), fp);
    file_password[strcspn(file_password, "\n")] = '\0';

    fgets(file_fullname, sizeof(file_fullname), fp);
    file_fullname[strcspn(file_fullname, "\n")] = '\0';

    fclose(fp);

    printf("\n->Please enter username: ");
    scanf(" %[^\n]", name_list);

    printf("\n->Please enter password: ");
    scanf(" %[^\n]", password_list);

    if (strcmp(name_list,file_username) == 0)
    {
        if (strcmp(password_list, file_password) == 0)
        {
            printf("\nBus reservation login successful. Welcome %s\n", file_fullname);
            return 1;
        }
        else
        {
            printf("\nInvalid username or password!\n");
            return 0;
        }
    }
}

int main()
{
     while (1)
    {   
        int output = bus_reservation_system();

        if (output == 1)
        {
            if (signup () == 1)
            {
                break;
            }
        }
        else if (output == 2)
        {
           if (login() == 1)
            {
                break; 
            }
        }
        else if (output == 3)
        {
            printf("\nExiting program...\n");
            break;
        }
        else
        {
            printf("\nInvalid choice! Please restart the program.\n");
        }
    }
    return 0;
}
