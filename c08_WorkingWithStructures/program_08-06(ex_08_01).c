//Illustrating Arrays of Structures, Version 1 - Edit w/ #define and Pointers
/*
	Program to illusrate arrays of structures
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 3

struct time
{
	int hours;
	int minutes;
	int seconds;
};

void timeUpdate (struct time *);

int main ()
{
	//Variables
	struct time testTime[TAM], *testPoint = NULL;

	testPoint = testTime;
	
	//Inputs
	for ( int i = 0; i < TAM; i++ ){ 
		printf ("Enter the Time (hh:mm:ss) for Test %i:\n", i);
		scanf ("%i:%i:%i", &(testPoint + i)->hours, &(testPoint + i)->minutes, &(testPoint + i)->seconds);
	}

	//Proceesing and Outputs
	for ( int i = 0; i < TAM; ++i ) {
		printf("Time is %.2i:%.2i:%.2i\n", testTime[i].hours, testTime[i].minutes, testTime[i].seconds);
		timeUpdate (testPoint + i);
 		printf (" ...one second later it's %.2i:%.2i:%.2i\n", testTime[i].hours, testTime[i].minutes, testTime[i].seconds);
	}

	return EXIT_SUCCESS;
}

//Function to update the time by one second
void timeUpdate (struct time *point)
{

    ++point->seconds;

    if (point->seconds == 60){
        point->seconds = 0;
        ++point->minutes;

        if (point->minutes == 60){
            point->minutes = 0;
            ++point->hours;

            if (point->hours == 24) point->hours = 0;
        }
    }
}