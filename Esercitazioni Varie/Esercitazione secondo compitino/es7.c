#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct e {
	int ne; //dimensione lista di adiacenza di un nodo
	int * edge; //array che contiene la lista di adiacenza di un nodo
} edges; 


typedef struct _queue {
	int* values;
	int capacity;
	int head;
	int tail;

} queue;


void init (queue* q, int capacity) {
	q->values=malloc(sizeof(int)* capacity);
	q->capacity=capacity;
	q->head=-1;
	q->tail=-1; //primo elemento vuoto
}

//1 se vuota0 altrimenti
int isEmpty(queue* q) {
	if (q->head == -1 && q->tail == -1)
		return 1;

	return 0;
}


//inserisci elemento
void ENQUEUE(queue* q, int value) {
	q->head++;
	if (q->tail==-1) q->tail++;
	q->values[q->head]=value;
	
}

//rimuovi elemento
int DEQUEUE(queue* q) {
	int elem;
	if (q->head==q->tail) {
		elem=q->values[q->head];
		q->head=-1;
		q->tail=-1;
		return elem;
	}
	else {
	elem=q->values[q->tail];
	q->tail++;
	return elem;
	}
}


void printQueue(queue* q) {
	if (q->tail==-1 && q->head==-1) {
		printf("Coda Vuota \n");
		return;
	}

	if (q->tail == q->head) {
		printf("[%d] \n", q->values[q->tail]);
		return;
	}

	for (int i=q->tail;i<=q->head;i++)
		printf("[%d] ", q->values[i]);

	printf("\n");

}

int *BFS (edges* G, int n, int* C, int* D, int src) {
	int u; int i; int dest;
	queue* Q = malloc(sizeof(queue));
		init(Q, n);

	for (i=0;i<n;i++) {
		C[i]=0;
	}

	for (i=0;i<n;i++) {
		D[i]=0;
	}

	C[src]=1;
	D[src]=0;
	ENQUEUE (Q, src);

	while (!isEmpty(Q)) {
	
		u=DEQUEUE (Q);

		for (i=0;i<G[u].ne;i++) {
			dest=G[u].edge[i];
			if (C[dest]==0) {
				C[dest]=1;
				D[dest]=D[u]+1;
				ENQUEUE (Q, dest);
			}//if
		}//for		
	C[u]=2;
	}//while 

	return C;
}


int main() {

int n, i, valore, j, k, bersaglio,min, indice;

scanf ("%d", &n);

edges* G= malloc (n * sizeof(struct e));

//array di colori
int *C= (int*) malloc (sizeof(int)*n);
//array delle distanze dal nodo sorgente
int *D= (int*) malloc (sizeof(int)*n);

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

//Inserisco k
scanf("%d", &k);
int* S= malloc(sizeof(int)*k);
for (i=0;i<k;i++) {
	scanf("%d", &valore);
	S[i]=valore;
}

//inserisco bersaglio
scanf("%d", &bersaglio);
//BFS
BFS (G, n, C, D, bersaglio);

//cerco vertice di S a distanza minima dal bersaglio
min=INT_MAX;

for(i=0;i<k;i++) {
	if (S[i]==1) {
		if (S[i] < min) {
			min=S[i];
			indice=i;
		}
	}
}

 
if (min==INT_MAX)
	printf("NULL");
else {
printf("%d", indice);
}


return 0;
}

