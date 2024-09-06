#include <stdio.h>

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 1; // Leap year
            else
                return 0; // Not a leap year
        } else
            return 1; // Leap year
    } else
        return 0; // Not a leap year
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

// Function to get the day of the week for the first day of the month
int getFirstDayOfMonth(int month, int year) {
    int day = 1;
    int k = year % 100;
    int j = year / 100;

    // Zeller's Congruence algorithm to calculate day of the week
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }

    int h = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    // Adjusting the result to match the format where Sunday is 0
    int dayOfWeek = ((h + 5) % 7) + 1;

    return dayOfWeek;
}

// Function to display the calendar for a given month and year
void displayMonthCalendar(int month, int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int daysInMonth = getDaysInMonth(month, year);
    int firstDay = getFirstDayOfMonth(month, year);

    printf("\n  ------------%s-------------\n", months[month - 1]);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 1; i < firstDay; i++) {
        printf("     ");
    }

    for (int day = 1; day <= daysInMonth; day++) {
        printf("%5d", day);

        if ((day + firstDay - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

// Function to display the calendar for a given year
void displayYearCalendar(int year) {
    for (int month = 1; month <= 12; month++) {
        displayMonthCalendar(month, year);
    }
}

int main() {
    int year;

    printf("Enter the year: ");
    scanf("%d", &year);

    displayYearCalendar(year);

    return 0;
}
