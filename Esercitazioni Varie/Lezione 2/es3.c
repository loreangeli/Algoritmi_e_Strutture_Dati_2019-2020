#include <stdio.h>

int my_strlen (char *s) {
	
	int i=0;
	while (*s != '\0') {
		i++;
		s++;
	}

	return i;
}

int main() {

char stringa[1001];
scanf("%s", stringa);

int cont=my_strlen (stringa);
printf("%d", cont);

return 0;
}
