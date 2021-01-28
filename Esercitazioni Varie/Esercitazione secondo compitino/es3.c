#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


typedef struct e {
	int ne; //dimensione lista di adiacenza di un nodo
	int * edge; //array che contiene la lista di adiacenza di un nodo
} edges; 


void DFS_visit (edges *G, int *C, int n, int X, int Y){
	for (int i=0;i<G[X].ne;i++) {
		int dest=G[X].edge[i];
		if (C[dest]==0) {
			C[dest]=1;
			DFS_visit (G, C, n, dest, Y);
		}
	}

	C[X]=2;
}

int DFS (edges *G,int *C, int n, int X, int Y, int Z) {
	//inizializzo i nodi a bianco
	for (int i=0;i<n;i++) C[i]=0;
	DFS_visit (G, C, n , X, Y);
	if (C[Y]==0) return 0;

	//inizializzo i nodi a bianco
	for (int i=0;i<n;i++) C[i]=0;
	DFS_visit (G, C, n , Y, Z);
	if (C[Z]==0) return 0;

	return 1;
}


void printC(int *C, int n) {
	for (int i=0;i<n;i++)
		printf ("%d", C[i]);
}


int main() {

int n, i, valore, j, X,Y,Z;

printf ("n \n");
scanf ("%d", &n);
printf ("X \n");
scanf ("%d", &X);
printf ("Y \n");
scanf ("%d", &Y);
printf ("Z \n");
scanf ("%d", &Z);


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

if (DFS(G, C, n , X, Y, Z) == 1) printf ("TRUE");
else printf ("FALSE");

return 0;
}

