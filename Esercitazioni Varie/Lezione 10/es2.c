#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct item {
	int key;
	struct item *next;
}; 

int hash (int x, int n, int a, int b) {
	int p=999149;

	int i=((a*x+b) % p) % (2*n);
	return i;
}


struct item** Insert (struct item** T,int A[],int B[], int x, int n, int a, int b) {
	//creo nodo 
	struct item* nodo= malloc (sizeof(struct item));
	nodo->key=x;
	nodo->next=NULL;
	//calcolo i=h(x)
	int i=hash (x, n ,a, b);

	//INSERIMENTO IN CODA
	struct item* c=T[i];
	//lista vuota
	if (T[i]==NULL) {
		T[i]=nodo;
		A[i]++;
		B[i]++;

	return T;
	}
	//altrimenti
		if (c->key == x) 
			return T;
	while (c->next != NULL) {
			if (c->key == x) 
			return T;
		c=c->next;
	}
	c->next=nodo;
	A[i]++;
	B[i]++;

	return T;
}


void print (struct item** T, int n) {
	int i;
	printf ("STAMPA: \n");
	//struct item** p=T;

	for (i=0;i<2*n;i++) {
		struct item* c=T[i];
		printf ("%d -> ", i);
		if (c == NULL)
			printf ("NULL ");
		while (c != NULL) {
			
			printf ("%d ", c->key);
			c=c->next;
		}
		printf ("\n");
	}
}



int lenghtmax (struct item** T, int n) {
	int i; int cont=0; int max=0;

	for (i=0;i<2*n;i++) {
		cont=0;
		struct item* c=T[i];
		while (c != NULL) {
			cont++;
			c=c->next;
		}
		if (cont>max) max=cont;
	}

return max;
}


int main() {

int n, a, b, i, x,conflitti, tot;
conflitti=0;
tot=0;

scanf ("%d", &n);
struct item** T= (struct item **) malloc (2*n * sizeof(struct item*));
//inizializzo il vettore di tipo item a NULL
for (i=0;i<2*n;i++) {
	T[i]=NULL;
}

int A[2*n];
int B[2*n];
//inizializza a 0
for (i=0;i<2*n;i++) {
	A[i]=0;
	B[i]=0;
}

scanf ("%d", &a);
scanf ("%d", &b);

for (i=0;i<n;i++) {
	scanf ("%d", &x);
	T=Insert (T,A,B,x, n, a, b);
}

	//print (T, n);


//numero conflitti
for (i=0;i<2*n;i++) {
	A[i]--;
	if (A[i]>0)
	conflitti=conflitti+A[i];
}
printf ("%d \n", conflitti);

//dimensione lista di lunghezza massima
	int max=lenghtmax (T, n);
	printf ("%d \n", max);

//numero totale di elementi distinti
for (i=0;i<2*n;i++) {
	tot=tot+B[i];
}
printf ("%d", tot);

return 0;
}

