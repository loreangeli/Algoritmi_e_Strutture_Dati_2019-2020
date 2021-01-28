#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* product (char *str, int k) {
	
	int h=0;
	char *s=(char*) malloc(sizeof(char)*(strlen(str)*k));	
	
	for (int i=0;i<k;i++) {
		for (int j=0;j<strlen(str);j++) {
			s[h]=str[j];
			h++;
		}
	}

	s[strlen(str)*k]='\0';

	return s;
}

int main () {

char str[1000];
int k;
char* p;

scanf("%s", str);
scanf ("%d", &k);

p=product(str, k);

printf("%s", p);

return 0;
}
