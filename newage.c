#include <stdio.h>

int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int isLeap(int year) 
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

void calculateAge(int birth_day, int birth_month, int birth_year) 
{
    int current_day, current_month, current_year;
    printf("Enter today's date: ");
    scanf("%d",&current_day);
    printf("Enter current month: ");
    scanf("%d",&current_month);
    printf("Enter current year: ");
    scanf("%d",&current_year);



    
    if (birth_day > current_day) {
        current_month--;
        current_day += daysInMonth[current_month];
        if (current_month == 2) // If February, adjust for leap year
            current_day += isLeap(current_year);
    }

   
    if (birth_month > current_month) 
    {
        current_year--;
        current_month += 12;
    }

   
    int day_diff = current_day - birth_day;
    int month_diff = current_month - birth_month;
    int year_diff = current_year - birth_year;

    printf("Your exact age is:  %d years, %d months, %d days\n", year_diff, month_diff, day_diff);
}

int main() {
    int birth_day, birth_month, birth_year;

    printf("Enter your birth year: ");
    scanf("%d", &birth_year);

    printf("Enter your birth month: ");
    scanf("%d", &birth_month);

    printf("Enter your birth date: ");
    scanf("%d", &birth_day);

    calculateAge(birth_day, birth_month, birth_year);

    return 0;
}