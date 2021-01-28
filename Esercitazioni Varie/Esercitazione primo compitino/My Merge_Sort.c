#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MERGE (int A[], int p, int q, int r) {
	//dichiaro variabili
	int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	//creo due nuovi array L e R di n1 posizioni e n2 posizioni
	int L[n1], R[n2];
	//riempio L
	for (i=0;i<n1;i++) {
		L[i]=A[p+i];
	}
	//riempio R
	for (j=0;j<n2;j++) {
		R[j]=A[q+1+j];
	}

    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = p; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            A[k] = L[i]; 
            i++; 
        } 
        else
        { 
            A[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        A[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        A[k] = R[j]; 
        j++; 
        k++; 
    } 

}

void MERGE_SORT (int A[], int p, int r) {

	if (p<r) {
		int q=(p+r)/2;
		MERGE_SORT (A, p, q);
		MERGE_SORT (A, q+1, r);
		MERGE (A, p, q , r);
	}
}


int main() {
//dichiaro variabili
int DIM; int i=0; int p=0; int r;
//dimensione array
printf("Dimensione Array: \n");
scanf("%d", &DIM);
//dichiara array 
int *A=(int *) malloc(DIM * sizeof(int));
//inserisci elementi in A
printf("Inserisci elementi: \n");
for (i=0;i<DIM;i++) {
	scanf("%d", &A[i]);
} 
//inserisci elementi in A
printf("\n STAMPA ARRAY PRIMA DEL MERGE_SORT \n");
for (i=0;i<DIM;i++) {
	printf("%d \n", A[i]);
} 
//chiama MERGE_SORT
r=DIM-1;
MERGE_SORT (A, 0, r);
//stampa array
printf("STAMPA ARRAY DOPO MERGE \n");
for (i=0;i<DIM;i++) 
	printf("%d \n", A[i]);


return 0;
}
