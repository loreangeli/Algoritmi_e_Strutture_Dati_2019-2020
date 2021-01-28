#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RicercaBinaria(char* A[], char* k, int sx, int dx) {
	if (sx > dx) return -1;
	if (sx==dx) {
		if ( strcmp(A[sx],k) == 0 ) return sx;
		else return -1;
	}
		int cx= (sx+dx)/2;
		if (strcmp(A[cx],k) == 0 ) { 
			return cx;
		}
		if (strcmp(A[cx],k) > 0 ){
			return RicercaBinaria(A, k, sx, cx-1);
		}
		else {
		return RicercaBinaria(A, k, cx+1, dx);
		}
}

int main () {

int N, i, val, DIM, rest;
char str[100];
//printf ("Inserisci il numero di stringhe da inserire: \n"); 
scanf("%d", &N);
//A e` l`array che contiene le parole ordinate lessicograficamente
char** A;
A= (char **) malloc (N * sizeof(char *));
char** search;
//l`array search contiene  un solo elemento all`inizio
search= (char **) malloc (sizeof(char *));
DIM=1;

for (i=0;i<N;i++) {
	A[i]= (char *) malloc (101* sizeof(char));
//	printf ("Inserisci la stringa %d: \n", i+1); 
	scanf("%s", A[i]);
}

//printf ("Inserisci il valore 0/1 ");
scanf ("%d", &val);
if (val==1) {
//printf ("Inserisci la stringa ");
scanf ("%s", str);
search[0]= (char *) malloc (101* sizeof(char));
strcpy (search[0], str);
}

i=1;

//printf ("Inserisci il valore 0/1 ");
scanf ("%d", &val);
while (val==1) {
//printf ("Inserisci la stringa ");
	scanf ("%s", str);
	DIM++;
	search=(char**) realloc (search, DIM * sizeof(char*));
	search[i]= (char *) malloc (101* sizeof(char));
	strcpy(search[i], str);
	i++;
	scanf ("%d", &val);
}


for (i=0;i<DIM;i++){
	rest= RicercaBinaria (A, search[i], 0, N-1);
	printf ("%d \n" ,rest);
}

return 0;
}
