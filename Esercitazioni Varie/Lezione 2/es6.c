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

int s1len=0;
int s2len=0;
char* s1;
char* s2;
char* s3;
//stringa s1
scanf("%d", &s1len);
s1=(char*) malloc(sizeof(char)*(s1len+1));
scanf("%s", s1);
s1[s1len]='\0';

//stringa s2
scanf("%d", &s2len);
s2=(char*) malloc(sizeof(char)*(s2len+1));
scanf("%s", s2);
s2[s2len]='\0';

s3=my_strcat1 (s1, s2);
printf("%s", s3);

return 0;
}
