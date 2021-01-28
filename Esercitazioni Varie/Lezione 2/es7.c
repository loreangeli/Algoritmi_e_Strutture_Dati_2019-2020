#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat (char *s1, char *s2) {
	int s1len=strlen(s1);
	int s2len=strlen(s2);
	
	for (int i=0;i<s2len;i++) {
		s1[s1len+i]=s2[i];
	}

	s1[s1len+s2len]='\0';

	return s1;
}

int main() {

char s1[2000];
char s2[1000];
char *s3;

scanf("%s",s1);
scanf("%s",s2);

s3=my_strcat(s1, s2);
printf("%s",s3);

return 0;
}
