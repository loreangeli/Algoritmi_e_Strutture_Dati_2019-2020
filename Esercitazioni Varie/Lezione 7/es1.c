#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
	char *stringa;
	int cont;
};

int confrontaA (const void *a, const void *b) {

	char **a1= (char **) a;
	char **b1= (char **) b;
		
	return strcmp(*a1, *b1);
}	

int confrontaB (const void *a, const void *b) {

	struct info *A= (struct info*) a;
	struct info *B= (struct info*) b;	

	if ( A->cont < B->cont) {
		return +1;
	}

	else return -1;
}	

	
int main () {

int N,K;
int i;
//dimensione di B
int DIMB;

scanf ("%d", &N);
scanf ("%d", &K);
//condizioni
 if (N<=0) return -1;
if (K>N) return -1;
//inizializza array di stringhe
char **A= (char**) malloc (sizeof(char*) * N);

for (i=0;i<N;i++) {
	A[i]= (char*) malloc (sizeof(char) * 101);
	scanf ("%s", A[i]);
}

qsort (A, N, sizeof(char*), confrontaA);


/*
//stampa dopo qsort
printf ("Array Ordinato: \n");
for (i=0;i<N;i++) {
	printf ("%s \n", A[i]);
}
*/


//inizializza la struttura
struct info * B = malloc ( sizeof(struct info) * N );
 
for (i=0;i<N;i++) {
	B[i].stringa= (char*) malloc (sizeof(char) * 101);
	B[i].cont=0;
}

strcpy (B[0].stringa, A[0]);
B[0].cont++;
DIMB=1;
for (i=1;i<N;i++) {
	if (strcmp (B[DIMB-1].stringa, A[i]) ==0 )
		B[DIMB-1].cont++;
	else {
		DIMB++;
		strcpy (B[DIMB-1].stringa, A[i]);
		B[DIMB-1].cont++;		
	}
}


/*
//stampa B
printf ("Array B: \n");
for (i=0;i<DIMB;i++) {
	printf ("%s ", B[i].stringa);
	printf ("%d \n", B[i].cont);
}
*/


//ordina B
qsort (B, DIMB, sizeof(struct info), confrontaB);


/*
//stampa B
printf ("Array B Ordinato: \n");
for (i=0;i<DIMB;i++) {
	printf ("%s ", B[i].stringa);
	printf ("%d \n", B[i].cont);
}
*/


//salva le prime K stringhe in un array C
char **C= (char**) malloc (sizeof(char*) * K );

for (i=0;i<K;i++) {
	C[i]=(char*) malloc (sizeof(char) * 101);
	strcpy (C[i], B[i].stringa);
}

qsort (C, K, sizeof(char*), confrontaA);

//STAMPA FINALE
for (i=0;i<K;i++) 	
	printf ("%s \n", C[i]);

return 0;
}
