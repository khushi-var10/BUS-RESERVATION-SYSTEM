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

// Booking
int numbers;
int seat;
int cancle;

struct Bus
{
    int bus_no;
    char route[50];
    char time[20];
    char date[20];
    int total_seats;
    int booked_seats;
    int fare;
};
struct Bus buses[5] = {
    {101, "Delhi to Jaipur", "3:00 PM", "13-Jan-2025", 40, 0, 500},
    {102, "Lucknow to Kanpur", "4:00 PM", "10-Jan-2025", 30, 0, 200},
    {103, "Chandigarh to Shimla", "10:00 AM", "25-June-2025", 35, 0, 450},
    {104, "Mumbai to Puna", "4:00 AM", "5-July-2025", 50, 0, 300},
    {105, "Bhubaneswar to Puri", "12:00 PM", "1-Feb-2025", 45, 0, 350}};

//=====main menu (signup / login / exit)=====
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

//=====user menu (after login/signup)=====
int menu()
{
    int choice;
    printf("\n\t============ USER MENU ============\t");
    printf("\n1. BooK a Ticket");
    printf("\n2. Cancle a Ticket");
    printf("\n3. Check Bus Status");
    printf("\n4. Logout");
    printf("\nPlease Enter a Choice: ");
    scanf("%d", &choice);
    return choice;
}

//=====sigup=====
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
            // Data save in file(overwrite)
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

//=====login=====
int login()
{
    FILE *fp;
    char file_username[200], file_password[200], file_fullname[200];

    // read file data
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

    if (strcmp(name_list, file_username) == 0)
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

//=====book a ticket=====
int book_a_ticket()
{
    // int numbers;
    // int seat;
    printf("\n\t\t\t************ BUS AVAILABLE ************\t\n");

    printf("\n\tS.No.\t\tName\t\t\tTime\t\t\tDate");
    printf("\n\t101\tDelhi to Jaipur  \t\t3:00 PM \t\t13-Jan-2025");
    printf("\n\t102\tLucknow to Kanpur \t\t4:00 PM \t\t10-Jan-2025");
    printf("\n\t103\tChandigarh to Shimla\t\t10:00 AM\t\t25-June-2025");
    printf("\n\t104\tMumbai to Puna\t\t\t4:00 AM \t\t5-July-2025");
    printf("\n\t105\tBhubaneswar to Puri\t\t12:00 PM\t\t1-Feb-2025\n");
    printf("\n\t************ BOOK A TICKET ************\t");

    printf("\nEnter Bus Number: ");
    scanf("%d", &numbers);
    printf("Enter Number Of Seats: ");
    scanf("%d", &seat);

    for (int i = 0; i < 5; i++)
    {
        if (buses[i].bus_no == numbers)
        {
            if (seat <= (buses[i].total_seats - buses[i].booked_seats))
            {
                buses[i].booked_seats += seat;
                printf("Booking successful ! %d seats booked on Bus Number %d\n", seat, numbers);
            }
            else
            {
                printf("Booking failed! Not enough seats.\n");
            }
            return 0;
        }
    }
}

//=====cancle ticket=====
int cancle_a_ticket()
{
    printf("\n\t************ CANCLE A TICKET ************\t");
    printf("\nEnter Bus Number: ");
    scanf("%d", &numbers);
    printf("Enter Number Of Seats to Cancle: ");
    scanf("%d", &cancle);

    for (int i = 0; i < 5; i++)
    {
        if (buses[i].bus_no == numbers)
        {
            if (cancle <= buses[i].booked_seats)
            {
                buses[i].booked_seats -= cancle;
                printf("Cancellation Successful ! %d seats cancled on Bus Number %d\n", cancle, numbers);
            }
            else
            {
                printf("Invalid cancellation request.\n");
            }
            return 0;
        }
    }
}

int check_bus_status()
{
    printf("\nEnter Bus Number to check status: ");
    scanf("%d", &numbers);

    for (int i = 0; i < 5; i++)
    {
        if (buses[i].bus_no == numbers)
        {
            printf("\nBus Number: %d", buses[i].bus_no);
            printf("\n=========== BUS STATUS ===========");
            printf("\nBus Number: %d", buses[i].bus_no);
            printf("\nRoute     : %s", buses[i].route);
            printf("\nTime      : %s", buses[i].time);
            printf("\nDate      : %s", buses[i].date);
            printf("\nTotal Seats   : %d", buses[i].total_seats);
            printf("\nBooked Seats  : %d", buses[i].booked_seats);
            printf("\nAvailable Seats: %d", buses[i].total_seats - buses[i].booked_seats);
            printf("\nFare per seat : Rs. %d", buses[i].fare);
            printf("\n==================================\n");
            return numbers;
        }
    }
    printf("\nInvalid Bus Number!\n");
}
//=====after login/signup: user menu loop=====
int user_menu_loop()
{
    while (1)
    {
        int choice = menu();
        if (choice == 1)
        {
            book_a_ticket();
        }

        else if (choice == 2)
        {
            cancle_a_ticket();
        }
        else if (choice == 3)
        {
            check_bus_status();
        }
        else if (choice == 4)
        {
            printf("\nLogging out...\n");
            return 0;
        }
        else
        {
            printf("\nInvalid choice! Try again.\n");
        }
    }
}
// ===== main function =====
int main()
{
    while (1)
    {
        int output = bus_reservation_system();

        if (output == 1)
        {
            if (signup() == 1)
            {
                if (user_menu_loop() == 0) // logout
                    break;
            }
        }
        else if (output == 2)
        {
            if (login() == 1)
            {
                if (user_menu_loop() == 0) // logout
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
