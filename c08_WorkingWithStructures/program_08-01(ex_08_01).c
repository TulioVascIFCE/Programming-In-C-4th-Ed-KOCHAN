// Program to Illustrate a Structure - Edit w/ Pointers

#include <stdio.h>

int main (void)
{
	//Local Structure
	struct  date
	{	
		int month;
		int day;
		int year;
	};
	
	//Variables
	struct date today, *dateP;

	//Pointer Assign
	dateP = &today;

	dateP->month = 6;
	dateP->day = 17;
	dateP->year = 2022;

	//Output
	printf  ("Normal: Today's date is %i/%i/%.2i.\n", today.month, today.day, today.year % 100);
	printf  ("Pointers: Today's date is %i/%i/%.2i.\n", dateP->month, dateP->day, dateP->year % 100);

	return 0;
}