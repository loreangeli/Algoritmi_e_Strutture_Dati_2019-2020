#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trepunti {
	int x;
	int y;
	int c;
};


struct quattropunti {
	int x1;
	int y1;
	int x2;
	int y2;
};



int confronta (const void *a, const void *b) {

	struct trepunti *A= (struct trepunti*) a;
	struct trepunti *B= (struct trepunti*) b;	

	if ( A->c == B->c) {
		return 0;
	}
	if ( A->c < B->c )
	 return -1;
	
	return +1;
}	


int interrogazione (struct trepunti* A, struct quattropunti* B, int i, int N, int M)  {

	int j,cont,DIMC=0;
	
	struct trepunti* C = malloc (sizeof(struct trepunti) * N);

		for (j=0;j<N;j++) {

			if ( (B[i].x1 <= A[j].x) && (A[j].x <= B[i].x2) && (B[i].y1 <= A[j].y) && (A[j].y <= B[i].y2) ) {
				DIMC++;
				C[DIMC-1].x=A[j].x;
				C[DIMC-1].y=A[j].y;
				C[DIMC-1].c=A[j].c;
			}		
		}


	//ordino C
	qsort (C, DIMC, sizeof(struct trepunti), confronta);

	//conto le occorrenze
	cont=0;
	if (DIMC > 0) {
		cont=1;
	}

	for (j=1;j<DIMC;j++) {
		if (C[j].c != C[j-1].c && j>0) 
			cont++;
	}
	
	return cont;
}
	
int main () {

int N,M,i, rest=0;

scanf ("%d", &N);
scanf ("%d", &M);

struct trepunti* A = malloc (sizeof(struct trepunti) * N);

for (i=0;i<N;i++) {
	scanf("%d", &A[i].x);
	scanf("%d", &A[i].y);
	scanf("%d", &A[i].c);
}


struct quattropunti* B = malloc (sizeof(struct quattropunti) * M);

for (i=0;i<M;i++) {
	scanf("%d", &B[i].x1);
	scanf("%d", &B[i].y1);
	scanf("%d", &B[i].x2);
	scanf("%d", &B[i].y2);
}

/*
/////////////////////////////////////////////////////////////////
//stampa N e M 
printf ("N (dimensione di A)=%d, M(dimensione di B)=%d \n", N,M);

//STAMPO A
printf ("Stampa A: \n");
for (i=0;i<N;i++) {
	printf("[%d,", A[i].x);
	printf("%d,", A[i].y);
	printf("%d] \n", A[i].c);
}

//STAMPO B
printf ("Stampa B: \n");
for (i=0;i<M;i++) {
	printf("[%d,", B[i].x1);
	printf("%d,", B[i].y1);
	printf("%d,", B[i].x2);
	printf("%d] \n", B[i].y2);
}
/////////////////////////////////////////////////////////////////
*/
//INTERROGAZIONI
for (i=0;i<M;i++) {
	rest=interrogazione (A,B,i,N,M);
	printf ("%d \n", rest);
}

return 0;
}
