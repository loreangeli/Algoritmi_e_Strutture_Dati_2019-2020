//es 6 pozzo
#include <stdio.h>
#include <stdlib.h>

typedef struct e {
	int ne; //dimensione lista di adiacenza di un nodo
	int * edge; //array che contiene la lista di adiacenza di un nodo
} edges; 


void printG (edges* G, int n) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<G[i].ne;j++)
			printf("%d ", G[i].edge[j]);
		printf("\n");
	}
	
}


int Cerca(edges* G, int i, int n) {
	int ris=1; int j=0;
	for (j=0;j<n;j++) {
			if (ris==0) return -1;
			ris=0;
		for (int h=0;h<G[j].ne;h++) {
			if (G[j].edge[h]==i || j == i)
				ris=1;
		}
		if (j==i)
			ris=1;
	}
	return +1;
}


int main () {

int n, i, j, ne, val, ris;
scanf("%d", &n);
edges* G= malloc(sizeof(edges)*n);

//inizializzo la lista di adiacenza
for (i=0;i<n;i++) {
	scanf("%d", &ne);
	G[i].edge=malloc(sizeof(int)*ne);
	G[i].ne=ne;

	for (j=0;j<ne;j++) {
		scanf("%d", &val);
		G[i].edge[j]=val;
	}
}
//

for (i=0;i<n;i++) {
	if (G[i].ne==0) {
		ris=Cerca(G, i, n);
		if (ris != -1) {
			printf("%d \n", i);
			return 0;
		}
	}
}

printf("-1 \n");

return 0;
}
