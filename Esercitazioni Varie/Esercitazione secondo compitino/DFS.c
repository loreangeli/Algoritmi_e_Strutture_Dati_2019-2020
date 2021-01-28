#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
// LEGENDA: 0: BIANCO 1: GRIGIO 2: NERO

typedef struct e {
	int ne; //dimensione lista di adiacenza di un nodo
	int * edge; //array che contiene la lista di adiacenza di un nodo
} edges; 


void print(edges* G, int n) {
	int i,j;

	for (i=0;i<n;i++) {
		printf("%d: ", G[i].ne);
		for (j=0;j<G[i].ne;j++) {
			printf ("%d ", G[i].edge[j]);	
		}	
		
		printf ("\n");
	}
}

//src: indice del nodo sorgente
void DFSricorsiva (edges *G, int u, int* C) {
	int dest;

	C[u]=1;

	for (int i=0;i<G[u].ne;i++) {
		dest=G[u].edge[i];
		if (C[dest]==0) {
			C[dest]=1;
			DFSricorsiva (G, dest, C);
		}
	}
		C[u]=2;
}

int* DFS (edges *G, int n, int *C) {

	//inizializzo colori
	for (int i=0;i<n;i++) {
		C[i]=0;
	}

	for (int j=0;j<n;j++) 
		if (C[j]==0) DFSricorsiva (G, j, C);
	
	return C;
}

void printC(int *C, int n) {
	for (int i=0;i<n;i++) {
		if (C[i]==0) printf("%d: Bianco", i);
		else if (C[i]==1) printf("%d: Grigio", i);
		else printf("%d: Nero", i);
		printf("\n");
	}	
}

int main() {

int n, i, valore, j;

scanf ("%d", &n);
edges* G= malloc (n * sizeof(struct e));
int *C= (int*) malloc (sizeof(int)*n);

//creo lista di adiacenza
for (i=0;i<n;i++) {
	scanf ("%d", &G[i].ne);
	G[i].edge= malloc (G[i].ne * sizeof(int));

	for (j=0;j<G[i].ne;j++) {
		scanf ("%d", &valore);
		G[i].edge[j]=valore;
	}
}
//

print(G, n);

DFS (G, n, C);

printC(C,n);

return 0;
}

