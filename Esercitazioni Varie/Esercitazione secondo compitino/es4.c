#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


typedef struct e {
	int ne; //dimensione lista di adiacenza di un nodo
	int * edge; //array che contiene la lista di adiacenza di un nodo
} edges; 

void printMatrice(int** M, int n) {
int i;
int j;

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%d ", M[i][j]);
		}
			printf ("\n");
	}
}


int** MatriceAdiacenza (edges* G, int **M, int n) {
int i,j;
for (i=0;i<n;i++) {
	for (j=0;j<G[i].ne;j++) {
		M[i][G[i].edge[j]]=1;
	}	
}

	return M;
}

int main() {

int n,i, j, valore;
scanf("%d", &n);

edges* G= malloc (n * sizeof(struct e));
int** M= (int**) malloc (n*sizeof(int*));

for (i=0;i<n; i++) {
	M[i]= (int *) malloc (n* sizeof(int));
}
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
//inizializzo matrice a 0
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			M[i][j]=0;
		}
	}


M= MatriceAdiacenza (G, M, n);
printMatrice(M, n);


return 0;
}

