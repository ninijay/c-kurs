#include <stdio.h>
#define PADDING "\t  "
int main(void){
	double c;
	signed int f;

	(void)printf("F'heit"PADDING"Celsius\n");
	(void)printf("-----------------\n");
	for(f = -100; f < 201; f+=20)
	{
		c = (5.00 * (f -32)) / 9.00;
		(void)printf("%6d"PADDING"%7.2f\n", f, c);
	}

	return 0;
}
