// Program to Determining Tomorrow’s Date (No Leap Year)
/*
	Suppose you want to write a simple program that accepts today’s date as input and displays 
	tomorrow’s date to the user.
*/

#include <stdio.h>

int main ()
{
	// Local Structure
	struct date
	{
		int month;
		int day;
		int year;
	};
	
	struct date today, tomorrow;

	int daysPerMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};

	puts("Enter today date (MM DD YYYY):");
	scanf("%i%i%i", &today.month, &today.day, &today.year);

	if ( today.day != *(daysPerMonths + today.month - 1) )
	{
		tomorrow.month = today.month;
		tomorrow.day = today.day + 1;
		tomorrow.year = today.year;
	}
	else if (today.month == 12)
	{ // End of Year
		tomorrow.month = 1;
		tomorrow.day = 1;
		tomorrow.year = today.year + 1;
	}
	else
	{ // End of Month
		tomorrow.month = today.month + 1;
		tomorrow.day = 1;
		tomorrow.year = today.year;
	}

	printf  ("Today's date is %i/%i/%.2i.\n", today.month, today.day, today.year % 100);
	printf  ("Tomorrow's date will be %i/%i/%.2i.\n", tomorrow.month, tomorrow.day, tomorrow.year % 100);

	return 0;
}