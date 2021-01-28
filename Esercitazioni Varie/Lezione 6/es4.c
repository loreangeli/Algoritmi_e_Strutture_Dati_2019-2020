#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stringhe {
	char* stringa;
	int dim;
};


int confronta (const void *a, const void *b) {

	struct stringhe *A= (struct stringhe*) a;
	struct stringhe *B=(struct stringhe*) b;	

	//caso in cui le stringhe sono lunghe uguali si guarda l-ordine lessicografico
	if ( A->dim == B->dim) {
		return strcmp(A->stringa, B->stringa);
	}
	//prima stringa e` piu corta della prima
	if (A->dim < B->dim)	return -1;

//prima stringa piu` lunga della prima
return 1;
}


int main () {

int DIM; int i; int dim;
scanf ("%d", &DIM);	

struct stringhe *A= malloc (sizeof(struct stringhe) * DIM);

for (i=0;i<DIM;i++) {
	A[i].stringa= malloc (sizeof(char) * 101);
	scanf ("%s", A[i].stringa);
	dim= strlen (A[i].stringa);
	A[i].dim=dim;
	
}

qsort (A, DIM, sizeof(struct stringhe), confronta);


for (i=0;i<DIM;i++) {
	printf ("%s \n", A[i].stringa);
	//printf ("%d \n", A[i].dim);
}


return 0;
}
