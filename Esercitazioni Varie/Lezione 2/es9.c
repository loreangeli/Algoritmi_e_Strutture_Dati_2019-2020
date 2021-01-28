#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_strcpy (char* dest, char* src) {

		for (int i=0;i<strlen(src);i++) {
			dest[i]=src[i];
		}
		
		dest[strlen(src)]='\0';

		return dest;
}

int main() {
	
char src[1000];
char *dest;
scanf("%s", src);
dest=(char*) malloc(sizeof(char)*(strlen(src)+1));

dest=my_strcpy(dest, src);

printf("%s", dest);

return 0;
}
