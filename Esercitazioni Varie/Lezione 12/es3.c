#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define SIZE 40

typedef struct e {
	int ne; //dimensione lista di adiacenza di un nodo
	int * edge; //array che contiene la lista di adiacenza di un nodo
} edges; 

typedef struct _query {
	int* a; //array che contiene elementi
} query;


struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void ENQUEUE(struct queue* q, int value){
    if(q->rear == SIZE-1)
       return; //printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int DEQUEUE(struct queue* q){
    int item;
    if(isEmpty(q)){
        //printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            //printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        //printf("Queue is empty");
    } else {
        //printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }//for
    }  //else  
}


int *BFS (edges* G, int n, int* C, int* D, int src) {
	int u; int i; int dest;
	//src e` il nodo sorgente di partenza
	struct queue* Q = createQueue();

	for (i=0;i<n;i++) {
		C[i]=0;
		D[i]=-1;
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


void printC(int *C, int n) {
	for (int i=0;i<n;i++)
		printf ("%d", C[i]);
}


void printD(int *D, int dim) {
	for (int i=0;i<dim;i++)
		printf ("%d", D[i]);
}

void printQuery (query *q, int n) {
	int i,j;

	for (i=0;i<n;i++) {
		for (j=0;j<2;j++)
			printf("%d", q[i].a[j]);
	}

}


int main() {

int n, i, valore, j, dim;

scanf ("%d", &n);

edges* G= malloc (n * sizeof(struct e));
//array colori nodi
int *C= (int*) malloc (sizeof(int)*n);
//array distanza dei nodi
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

scanf ("%d", &dim);
query* q= malloc (sizeof(struct _query)*dim);
//creo lista delle Query
for (i=0;i<dim;i++) {
	q[i].a=malloc (sizeof(int)*2);
	for (j=0;j<2;j++) {
		scanf("%d", &valore);
		q[i].a[j]=valore;
	}
}


for (i=0;i<dim;i++) {
	BFS (G, n, C, D , q[i].a[0]);
	int dest=q[i].a[1];
	printf("%d", D[dest]);
	printf("\n");
}



return 0;
}

