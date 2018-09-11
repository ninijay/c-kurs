#include <stdio.h>
#define TRUE 1
#define FALSE 0


int main(void){
	int cnt = 0;
	int cnt_words = 0;
	int c;
	int hasWord = FALSE;
	while((c = getchar()) != '\n' && c != EOF){
		cnt++;
		if(!hasWord && c != ' ' &&  c != '\t'){
			hasWord = TRUE;
			cnt_words++;
		}
		if((c == ' ' || c == '\t') && hasWord)
			cnt_words++;
	}

	(void)printf("Anzahl Zeichen %7d\n", cnt);
	(void)printf("Anzahl Wörter %7d\n", cnt_words);
	return 0;
}
