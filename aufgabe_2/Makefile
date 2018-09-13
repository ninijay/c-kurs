all: next_day
next_day: next_day.c
	gcc -Wall -g -o next_day next_day.c
test: next_day.c test.c
	gcc -o test test.c next_day.c -lcunit
