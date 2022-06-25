// Program to update the time by one second- Edit w/ Pointers
/*
	You have the need to store values inside a program that represents various times 
	expressed as hours, minutes, and seconds and updates the time by one second
*/
#include <stdio.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

void timeUpdate(struct time *, struct time *);

int main ()
{
    struct time currentTime, nextTime;
    struct time *currentTimePoint, *nextTimePoint;

    currentTimePoint = &currentTime;
    nextTimePoint = &nextTime;

    puts("Enter the time (hh:mm:ss):");
    scanf("%i:%i:%i", &currentTimePoint->hours,
            &currentTimePoint->minutes, &currentTimePoint->seconds);

    timeUpdate(currentTimePoint, nextTimePoint);

    printf("Updated time is %.2i:%.2i:%.2i.\n",
            nextTimePoint->hours, nextTimePoint->minutes, nextTimePoint->seconds);

    return 0;

}

//Function to update the time by one second

void timeUpdate (struct time *userTime, struct time *nowTime)
{
    nowTime->hours = userTime->hours;
    nowTime->minutes = userTime->minutes;
    nowTime->seconds = userTime->seconds;

    ++nowTime->seconds;

    if (nowTime->seconds == 60){
        nowTime->seconds = 0;
        ++nowTime->minutes;

        if (nowTime->minutes == 60){
            nowTime->minutes = 0;
            ++nowTime->hours;

            if (nowTime->hours == 24) nowTime->hours = 0;
        }
    }
}