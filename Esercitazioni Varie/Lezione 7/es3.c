#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stringhe {
	char *stringa;
	int id;
};

void Print(struct stringhe* A, int N) {

	for (int i=0;i<N;i++) {
		printf ("%s ", A[i].stringa);
		printf ("%d \n", A[i].id);
	}
}

int confronta (const void *a, const void *b) {
	char *a1= (char*)a;	
	char *b1= (char*)b;	
	
	return strcmp (a1,b1);
}

int confronta2 (const void *a, const void *b) {
	struct stringhe *a1= (struct stringhe*)a;	
	struct stringhe *b1= (struct stringhe*)b;	

	return strcmp (a1->stringa,b1->stringa);
}



int main () {

int N,i;
scanf ("%d", &N);

struct stringhe *A= malloc (sizeof (struct stringhe) * N);
struct stringhe *B= malloc (sizeof (struct stringhe) * N);


for (i=0;i<N;i++) {
	A[i].stringa= malloc (sizeof (char) * 21);
	scanf ("%s", A[i].stringa);
	A[i].id=i;
}

//copio A in B
for (i=0;i<N;i++) {
	B[i].stringa= malloc (sizeof (char) * 21);
	strcpy (B[i].stringa,A[i].stringa);
	B[i].id=A[i].id;
}

/*
//STAMPA A
printf ("Stampo Array A: \n");
Print (A, N);
*/

//ordino B per stringhe uguali
qsort (B, N, sizeof(struct stringhe), confronta2);

/*
//STAMPA B
printf ("Stampo Array B [parole ordinate 1]: \n");
Print (B, N);
*/

//modifico le stringhe di B
for (i=0;i<N;i++) {
	qsort (B[i].stringa, strlen(B[i].stringa), sizeof(char), confronta);
}

/*
//STAMPA B
printf ("Stampo Array B [singole parole ordinate]: \n");
Print (B, N);
*/

//ordino B per stringhe uguali
qsort (B, N, sizeof(struct stringhe), confronta2);

/*
//STAMPA B
printf ("Stampo Array B [parole ordinate 2]: \n");
Print (B, N);
*/

//STAMPO RISULTATO
for (i=0;i<N;i++) {
	if ( (i>0) && (strcmp (B[i].stringa, B[i-1].stringa)!=0) ) 
		printf ("\n");
	printf ("%s ", A[B[i].id].stringa);
}

return 0;
}
