#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp(char *s1, char *s2) {
	
	if (strlen(s1) < strlen(s2)) return -1;
	if (strlen(s1) > strlen(s2)) return +1;
	
	for (int i=0;i<strlen(s1);i++) {
		if (s1[i] < s2[i]) return -1;
		else if (s1[i]>s2[i]) return +1;
	}
	
	return 0;
}


int main() {

char s1[1000];
char s2[1000];
int ris;

scanf("%s", s1);
scanf("%s", s2);

ris=my_strcmp(s1, s2);

printf("%d", ris);

return 0;
}
