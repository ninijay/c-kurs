#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 128

int needFor6 = 0;
int points[MAX_STUDENTS];
void getStatistics(void);
typedef enum {false, true} bool;

int main(void){
	int i = 0;
	bool isDone = false;	
	(void)printf("Bitte geben Sie alle erreichten Punktzahlen ein und beenden Sie Ihre Eingabe mit einem -1:\n");	
	while(!isDone){
		int tmp;
		scanf("%d", &tmp);
		if((int)tmp < -1 )
		{
			isDone = true;
			(void)printf("Ihre Eingabe war ungültig");
			return EXIT_FAILURE;
		}
		if((int)tmp == -1){
			isDone = true;
			points[i] = tmp;
		}
		points[i] = tmp;
		i++;
	}	
	(void)printf("Bitte geben Sie jetzt die benötigte Anzahl Punkte für eine 6 ein:\n");
	scanf("%d", &needFor6);
	getStatistics();
	return EXIT_SUCCESS;
}

int getMark(int pts);
void printLn(void);
void getStatistics(void){
	int noten[] = {0,0,0,0,0,0};
	int best = 0, worst = 0, cnt = 0, cntOver4 = 0;
	double avg = 0.00, over4inPerc = 0.00;
	// count all
	for(int i = 0; (int)points[i] != -1; i++){
		noten[getMark(points[i])-1] += 1;
		cnt++;
	}
	// get worst
	int i = 0;
	while(worst==0)
	{
		if(noten[i])
			worst = (i+1);
		i++;
	}	
	// get best
	i = 5;
	while(best==0){
		if(noten[i])
			best = (i+1);
		i--;
	}
	// get avg
	int tmp=0;
	for(int i = 0; i < 6; i++)
		tmp += (i+1)*noten[i];
	avg = (double)tmp/cnt;
	// get below 4
	for(int i = 3; i <6; i++)
		cntOver4+= noten[i];
	over4inPerc = (double)cntOver4*100/cnt;
	(void)printLn();
	(void)printf("Statistics (%d students, %d points needed for mark 6)\n\n", cnt, needFor6);
	for(int i = 5; i > -1; i--)
		(void)printf("Mark %d: %d\n", (i+1), noten[i]);
	(void)printf("\nBest mark:\t%d\nWorst mark:\t%d\nAverage mark:\t%.2f\nMark >=4:\t%d students (%.2f %%)\n", best, worst, avg, cntOver4, over4inPerc);
	(void)printLn();
}

int getMark(int pts){
	double tmp = 1.00 + ((5.00*(double)pts)/needFor6);
	if(tmp >= 5.50)
	{
		return 6;
	}
	int tmp2 = (int)tmp;
	if((tmp-tmp2) >= 0.50)
	{
		return (int)ceil(tmp);
	}
	else{
		return (int)floor(tmp);
	}
}

void printLn(void){
	(void)printf("--------------------------------------------------------\n");
}
