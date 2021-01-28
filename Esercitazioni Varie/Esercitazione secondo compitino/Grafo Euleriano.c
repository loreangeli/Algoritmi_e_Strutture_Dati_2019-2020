#include <stdio.h>
#include <stdlib.h>


typedef struct _edges {
	int numnodi;
	int* edges;
} edges;


int *BFS (edges* G, int n, int* C) {
	int u; int i; int dest;
	struct queue* Q = createQueue();

	for (i=0;i<n;i++) {
		C[i]=0;
	}

	C[0]=1;
	ENQUEUE (Q, 0);

	while (!isEmpty(Q)) {
	
		u=DEQUEUE (Q);

		for (i=0;i<G[u].ne;i++) {
			dest=G[u].edge[i];
			if (C[dest]==0) {
				C[dest]=1;
				ENQUEUE (Q, dest);
			}//if
		}//for		
	C[u]=2;
	}//while 

	return C;
}


int main() {

int n, val, i,j;
scanf("%d", &n);
edges* G= (edges*) malloc (sizeof(edges)*n);
int* C=malloc(sizeof(int)*n);

//creo lista di adiacenza
for (i=0;i<n;i++) {
	scanf("%d", &G[i].numnodi);
	G[i].edges= malloc(G[i].numnodi * sizeof(int));
	
	for (j=0;j<G[j].numnodi;j++) {
		scanf("%d", &val);
		G[i].edges[j]=val;		
	}
}
//

BFS(G, n, C);
for (i=0;i<n;i++) {
	if (C[i]==0) {
		printf("Non Euleriano \n");
		return 0;
	}
}

//controllo il grado di ogni nodo, guardo la lista di adiacenza
for (i=0;i<n;i++)
	if (G[i].numnodi % 2 != 0) {
		printf("Non Euleriano \n");
		return 0;
	}
}
		
printf("Grafo Euleriano \n");

return 0;
}
