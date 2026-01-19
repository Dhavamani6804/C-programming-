#include <stdio.h>
#include <stdlib.h>

// Structure for date
struct Date {
    int day;
    int month;
    int year;
};

// Function prototypes
int isLeapYear(int year);
int daysInMonth(int month, int year);
int daysBetweenDates(struct Date d1, struct Date d2);
struct Date getDateInput();

int main() {
    struct Date date1, date2;
    
    printf("-------DATE CALCULATOR-------\n");
    
    // Get first date
    printf("\nEnter First Date:\n");
    date1 = getDateInput();
    
    // Get second date
    printf("\nEnter Second Date:\n");
    date2 = getDateInput();
    
    // Calculate and display difference
    int difference = daysBetweenDates(date1, date2);
    printf("\nDate 1: %02d/%02d/%04d\n", date1.day, date1.month, date1.year);
    printf("Date 2: %02d/%02d/%04d\n", date2.day, date2.month, date2.year);
    printf("Days between dates: %d\n\n", difference);
    
    return 0;
}

// Function to get date input from user
struct Date getDateInput() {
    struct Date d;
    int valid;
    
    do {
        valid = 1;
        
        printf("Enter day (1-31): ");
        scanf("%d", &d.day);
        
        printf("Enter month (1-12): ");
        scanf("%d", &d.month);
        
        printf("Enter year: ");
        scanf("%d", &d.year);
        
        // Validate month
        if(d.month < 1 || d.month > 12) {
            printf("Invalid month! Please enter between 1-12.\n");
            valid = 0;
            continue;
        }
        
        // Validate day for given month and year
        int maxDays = daysInMonth(d.month, d.year);
        if(d.day < 1 || d.day > maxDays) {
            printf("Invalid day! For month %d/%d, day must be between 1-%d.\n", 
                   d.month, d.year, maxDays);
            valid = 0;
        }
        
    } while(!valid);
    
    return d;
}

// Function to check if a year is leap year
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Function to get number of days in a month
int daysInMonth(int month, int year) {
    switch(month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

// Function to calculate days between two dates
int daysBetweenDates(struct Date d1, struct Date d2) {
    
    // Function to convert date to days
    long int daysFromReference(struct Date d) {
        long int days = d.day;
        
        // Add days from previous months of current year
        for(int i = 1; i < d.month; i++) {
            days += daysInMonth(i, d.year);
        }
        
        // Add days from previous years
        days += (d.year - 1) * 365L;
        
        // Add leap days
        days += (d.year - 1) / 4;
        days -= (d.year - 1) / 100;
        days += (d.year - 1) / 400;
        
        return days;
    }
    
    // Calculate days for both dates
    long int days1 = daysFromReference(d1);
    long int days2 = daysFromReference(d2);
    
    // Return absolute difference
    long int difference = days1 - days2;
    if(difference < 0) difference = -difference;
    
    return (int)difference;
}