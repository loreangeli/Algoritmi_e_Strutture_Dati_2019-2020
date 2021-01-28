#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int confrontaStringhe (const void *a, const void *b) {
	char **a1= (char**) a; 
	char **b1= (char**) b;
	
	return strcmp (*b1, *a1);

}



int main () {

int DIM; int i; 
scanf ("%d", &DIM);	

char **A=(char**) malloc (sizeof(char*) * DIM);

for (i=0;i<DIM;i++) {
	A[i]= (char*) malloc (sizeof(char) * 101);
	scanf ("%s", A[i]);
}
qsort (A, DIM, sizeof(char*), confrontaStringhe);

for (i=0;i<DIM;i++)
	printf ("%s \n", A[i]);


return 0;
}
