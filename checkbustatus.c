#include <stdio.h>

struct Bus
{
    int bus_no;
    char route[50];
    char time[20];
    char date[20];
    int total_seats;
    int booked_seats;
    int fare;
} buses[5] = {
    {101, "Delhi to Jaipur", "3:00 PM", "13-Jan-2025", 40, 5, 500},
    {102, "Lucknow to Kanpur", "4:00 PM", "10-Jan-2025", 30, 10, 200},
    {103, "Chandigarh to Shimla", "10:00 AM", "25-June-2025", 35, 7, 450},
    {104, "Mumbai to Pune", "4:00 AM", "5-July-2025", 50, 20, 300},
    {105, "Bhubaneswar to Puri", "12:00 PM", "1-Feb-2025", 45, 12, 350}};

void check_bus_status()
{
    int number, i, found = 0;
    printf("\n************ CHECK BUS STATUS ************\n");
    printf("Enter Bus Number: ");
    scanf("%d", &number);

    for (i = 0; i < 5; i++)
    {
        if (buses[i].bus_no == number)
        {
            found = 1;
            printf("\nBus Number: %d", buses[i].bus_no);
            printf("\nRoute: %s", buses[i].route);
            printf("\nDate: %s", buses[i].date);
            printf("\nTime: %s", buses[i].time);
            printf("\nTotal Seats: %d", buses[i].total_seats);
            printf("\nBooked Seats: %d", buses[i].booked_seats);
            printf("\nAvailable Seats: %d", buses[i].total_seats - buses[i].booked_seats);
            printf("\nFare per Seat: Rs %d\n", buses[i].fare);
            break;
        }
    }
}

int menu()
{
    int choice;
    printf("\n\t============USER MENU============\t");
    printf("\n1. Book a Ticket");
    printf("\n2. Cancel a Ticket");
    printf("\n3. Check Bus Status");
    printf("\n4. Logout");
    printf("\nPlease Enter a Choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int output = menu();

    if (output == 3)
    {
        check_bus_status();
    }

    return 0;
}
