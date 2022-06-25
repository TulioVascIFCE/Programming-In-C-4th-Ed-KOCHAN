// Program to Illustrate a Structure - Edit w/ Pointers
#include <stdio.h>

int main (void)
{
	struct  date
	{	
		int month;
		int day;
		int year;
	};

	struct date today, *dateP;

	dateP = &today;

	dateP->month = 6;
	dateP->day = 17;
	dateP->year = 2022;

	printf  ("Normal: Today's date is %i/%i/%.2i.\n", today.month, today.day, today.year % 100);
	printf  ("Pointers: Today's date is %i/%i/%.2i.\n", dateP->month, dateP->day, dateP->year % 100);

	return 0;
}