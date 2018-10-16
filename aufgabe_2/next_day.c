#include <stdio.h>
#include <stdlib.h>
#define FIRST_YEAR 1583
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
bool isDateValid(Date *dt);

bool isNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i])){
	    (void)printf("%s is not a valid number\n", number);
            return false;
	}
    }
    return true;
}

void printDate(Date *dt){
	(void)printf("%d-%d-%d", dt->day, dt->month, dt->year);
}
int main(int argc, char *argv[]){
	if (argc < 3 || argc > 4){
		(void)printf("Not enough args\n");
		(void)printf("Usage:\n\tnext_day <day> <month> <year>\nExample:\n\tnext_day 12 12 2003\n");
		return EXIT_FAILURE;
	}
	Date *today;
        today = malloc(sizeof(Date));
	if(today == NULL){
		(void)printf("Error during memmory allocation\n");
		return EXIT_FAILURE;
	}
	if(!isNumber(argv[1]))
		return EXIT_FAILURE;
	today->day = strtol(argv[1], NULL, 10);
	if(!isNumber(argv[2]))
		return EXIT_FAILURE;
	today->month = strtol(argv[2], NULL, 10);
	if(!isNumber(argv[3]))
		return EXIT_FAILURE;
	today->year = strtol(argv[3], NULL, 10);
	if(!isDateValid(today)){
		(void)printf("Date is invalid!\n");
		return EXIT_FAILURE;
	}
	(void)printf("Your Date: ");
	(void)printDate(today);
	(void)printf("\n");
	(void)printf("The next day: ");
	(void)printDate(getNextDay(today));	
	(void)printf("\n");
	return EXIT_SUCCESS;
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
	if(nextMonth > Dec){
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

bool isDateValid(Date *dt){
	if(dt->year<FIRST_YEAR)
		return true;
	if(dt->month < Jan || dt->month > Dec)
		return false;
	
	bool leap = isLeap(dt->year);
	if(dt->day > daytab[leap][dt->month])
		return false;
	return true;
}
