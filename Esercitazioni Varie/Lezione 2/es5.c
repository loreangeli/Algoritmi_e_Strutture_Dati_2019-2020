#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat1(char *s1, char*s2) {
	int s1len=strlen(s1);
	int s2len=strlen(s2);

	//stringa che contiene la concatenazione
	char* str=(char*) malloc(sizeof(char)*(s1len+s2len+1));
	//controllo il buon esito della allocazione
	if (str==NULL) {
	printf("Allocazione fallita \n");
	}
	//copio s1 nella stringa str
	for (int i=0;i<s1len;i++) {
		str[i]=s1[i];
	}

	//copio s2 nella stringa str
	for (int i=0;i<s2len;i++) {
		str[i+s1len]=s2[i];
	}
	str[s1len+s2len]='\0';

	return str;
}

int main() {

char s1[1000];
char s2[1000];
char* s3;
scanf("%s", s1);
scanf("%s", s2);

s3=my_strcat1(s1,s2);
printf("%s", s3);

return 0;
}
