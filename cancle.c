#include <stdio.h>

int menu()
{
    int choice;
    printf("\n\t============USER MENU============\t");
    printf("\n1. BooK a Ticket");
    printf("\n2. Cancle a Ticket");
    printf("\n3. Check Bus Status");
    printf("\n4. Logout");
    printf("\nPlease Enter a Choice: ");
    scanf("%d", &choice);
    return choice;
}

int cancle_a_ticket()
{
    int number;
    int cancle;
    printf("\n\t************ CANCLE A TICKET ************\t");
    printf("\nEnter Bus Number: ");
    scanf("%d", &number);
    printf("Enter Number Of Seats to Cancle: ");
    scanf("%d", &cancle);
    printf("Cancellation Successful ! %d seats cancled on Bus Number %d\n", cancle, number);
}

int main()
{
    int output = menu();

    if (output == 2)
    {
        cancle_a_ticket();
    }
    return 0;
}