#include <stdio.h>
int numbers;
int seat;
int cancle;
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
    printf("Booking successful ! %d seats booked on Bus Number %d\n", seat, numbers);
}
int main()
{
    int output = menu();

    if (output == 1)
    {
        book_a_ticket();
    }
    return 0;
}