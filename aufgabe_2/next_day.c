#include <stdio.h>
#include <stdlib.h>
// preparation with month names, days in months and bools
enum {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
typedef enum {false, true} bool;
typedef struct {
	int day;
	int month;
	int year;
} Date;

Date* getNextDay(Date *today);
void printDate(Date *dt){
	(void)printf("%d-%d-%d", dt->day, dt->month, dt->year);
}
int main(int argc, char *argv[]){
	if (argc < 3 || argc > 4)
		return EXIT_FAILURE;
	Date *today;
        today = malloc(sizeof(Date));
	if(today == NULL)
		return EXIT_FAILURE;
	today->day = strtol(argv[1], NULL, 10);
	today->month = strtol(argv[2], NULL, 10);
	today->year = strtol(argv[3], NULL, 10);
	(void)printf("Your Date: ");
	(void)printDate(today);
	(void)printf("\n");
	(void)printf("The next day: ");
	(void)printDate(getNextDay(today));	
	(void)printf("\n");
	return 0;
}


bool isLeap(int year);
Date* getNextDay(Date *today){
	bool leap = isLeap(today->year);
	int nextDay = today->day;
	int nextMonth = today->month;
	int nextYear = today->year;
	Date *next = malloc(sizeof(Date));
	if(next == NULL)
		return 0;
	// check if next month
	if((nextDay+1) > daytab[leap][nextMonth]){
		nextDay = 1;
		nextMonth++;
	}
	else{
		nextDay++;
	}
	
	// check if next year
	if(nextMonth > 12){
		nextMonth = 1;
		nextYear++;
	}

	next->day = nextDay;
	next->month = nextMonth;
	next->year = nextYear;

	return next;
}

bool isLeap(int year){
	return ((year%4 == 0 && year%100 != 0) || year%400 == 0);
}
