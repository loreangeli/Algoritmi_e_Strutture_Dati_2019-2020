#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct Queue {
	int N; //dimensione max array
	int* A; //array di N elementi
	int size; //numero degli elementi presenti in coda
}; 

struct Queue* inizQueue (struct Queue* Q, int N) {
	Q= malloc (sizeof(struct Queue));
	Q->size=0;
	Q->N=N;
	Q->A= malloc (sizeof(int)* N);
	//inizializzo a 0
	for (int i=0;i<N;i++)
		Q->A[i]=0;

	return Q;
}


int search (struct Queue* Q, int x) {
	int i;
	for (i=0;i<Q->size;i++) {
		if (Q->A[i]==x)
			return i;
	}
	
	return -1;	
}

void insert (struct Queue* Q, int x) {
	int j,i;
	int ris=search(Q, x); // -1 se non presente, altrimenti indice elemento

	if (ris != -1) { //x presente in Q
		int *A1= malloc (sizeof(int)* (Q->N) );
		A1[0]=x;
		j=1;
		for (i=0;i<Q->size;i++) {
			if (i!=ris) {
				A1[j]=Q->A[i];
				j++;
			}
		}
		//ricopio A1 in A
		for (i=0;i<Q->size;i++) {
				Q->A[i]=A1[i];
		}

		free(A1);
	}

	else if (ris == -1) { //x non presente in Q
		if (Q->size == Q->N) { //coda piena
			int *A1= malloc (sizeof(int)* (Q->N) );
			A1[0]=x;
			j=1;

				for (i=0;i<Q->size-1;i++) {
					A1[j]=Q->A[i];
					j++;
				}
				//ricopio A1 in A
				for (i=0;i<Q->size;i++) {
						Q->A[i]=A1[i];
				}

			free(A1);
	   }//chiudoif

		else { //coda non piena

			int *A1= malloc (sizeof(int)* (Q->N) );
			j=1;

				for (i=0;i<Q->size;i++) {
					A1[j]=Q->A[i];
					j++;
				}
				A1[0]=x;
				Q->size++;
				//ricopio A1 in A
				for (i=0;i<Q->size;i++) {
						Q->A[i]=A1[i];
				}

				free(A1);	
	
		}//chiudoelse
	}//chiudoelseif
}//chiudoinsert

void print (struct Queue* Q) {
	int i;
	for (i=0;i<Q->size;i++)
		printf("%d ", Q->A[i]);

	printf ("$ \n");	
}


int main() {

int N, e, x;
scanf("%d", &N);
struct Queue* coda=NULL;
coda=inizQueue (coda, N);
scanf("%d", &e);


while (e!=0) {
	if (e==1) {
		scanf("%d", &x);
		insert (coda, x);
	}
	else print (coda);

	scanf("%d", &e);
}


return 0;
}

