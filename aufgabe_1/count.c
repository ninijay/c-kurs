#include <stdio.h>

int main(void){
	int cnt = 0;
	int cnt_words = 1;
	int c;
	while((c = getchar()) != '\n' && c != EOF){
		cnt++;
		if(c == ' ' || c == '\t')
		{
			cnt_words++;
		}
	}

	(void)printf("Anzahl Zeichen %7d\n", cnt);
	(void)printf("Anzahl Wörter %7d\n", cnt_words);
	return 0;
}
