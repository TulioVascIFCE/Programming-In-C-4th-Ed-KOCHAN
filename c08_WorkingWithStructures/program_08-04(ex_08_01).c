// Revising the Program to Determine Tomorrow’s Date, Version 2 (w/ Leap Year)
/*
	Suppose you want to write a simple program that accepts today’s date as input and displays 
	tomorrow’s date to the user.
*/

#include <stdio.h>

// Global Structure
struct date
{
	int month;
	int day;
	int year;
};

// Functions Prototype
struct date dateUpdate (struct date);
int numbersOfDays(struct date);
char isLeapYear(struct date);

int main ()
{
	//Variables
	struct date today, tomorrow;

	// Inputs
	puts("Enter today date (MM DD YYYY):");
	scanf("%i%i%i", &today.month, &today.day, &today.year);

	// Processing
	tomorrow = dateUpdate(today);
	
	// Output
	printf  ("Today's date is %i/%i/%.2i.\n", today.month, today.day, today.year % 100);
	printf  ("Tomorrow's date will be %i/%i/%.2i.\n", tomorrow.month, tomorrow.day, tomorrow.year % 100);

	return 0;
}

// Function to calculate tomorrow's date

struct date dateUpdate (struct date d)
{
	struct date nextDay;
	
	if ( d.day != numbersOfDays (d) )
	{
		nextDay.month = d.month;
		nextDay.day = d.day + 1;
		nextDay.year = d.year;
	}
	else if (d.month == 12)
	{ // End of Year
		nextDay.month = 1;
		nextDay.day = 1;
		nextDay.year = d.year + 1;
	}
	else
	{ //End of Month
		nextDay.month = d.month + 1;
		nextDay.day = 1;
		nextDay.year = d.year;
	}

	return nextDay;
}

// Function to find the numbers of days in a month

int numbersOfDays(struct date d)
{
	int days;
	const int daysPerMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};

	if ( isLeapYear(&d) == '1' && d.month == 2 ) days = 29;
	else days = *(daysPerMonths + d.month - 1);

	return days;
}

// Function to determiine if it's a leap year

char isLeapYear (struct date d)
{
	char leapYearFlag;

	if ( (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) leapYearFlag = '1'; // It's a leap year
	else leapYearFlag = '0'; // Not a leap year

	return leapYearFlag;
}