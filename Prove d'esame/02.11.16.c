//02.11.16 portale algo1617/Esami 2015-2016
#include <stdio.h>
#include <stdlib.h>
#define p 999149
#define a 7
#define b 20

typedef struct _node {
	struct _node* next;
	int value;
} item;


item** insert(item** T, int N, int key) {
	item* nodo=malloc(sizeof(item));
	nodo->value=key;	
	nodo->next=NULL;
	//funzione hash
	int hash= ((a*key+b) % p) % N;
	//inserimento in testa
	if (T[hash] == NULL) {
		T[hash]=nodo;
		return T;
	}
	else {
		nodo->next=T[hash];	
		T[hash]=nodo;
		return T;
	}
}


void printHash(item** T, int N) {
	item* punt=NULL;

	for (int i=0;i<N;i++) {
		punt=T[i];
		printf("[%d] ", i);
		while (punt != NULL) {
			printf("%d ", punt->value);
			punt=punt->next;
		}
		printf ("\n");
	}

}


int contakey (item** T, int key, int N) {
	//funzione hash
	int hash= ((a*key+b) % p) % N;
	int cont=0;
	item* punt=T[hash];
	while (punt!=NULL) {
		if (punt->value==key) {
			cont++;
		}
		punt=punt->next;
	}
	return cont;
}


int main() {

int N, K, val, i;
scanf("%d", &N);
scanf("%d", &K);
int* A= malloc(sizeof(int)*N);
item** T= malloc (sizeof(item*)*N);

for (i=0;i<N;i++)
	T[i]=NULL;


for (i=0;i<N;i++) {
	scanf("%d", &val);
	A[i]=val;
	T=insert(T, N, val);
}


for (i=0;i<N;i++) {
	int cont=contakey(T, A[i], N);
	if (cont>=K) {
			printf("%d ", A[i]);
	}
		
}


return 0;
}
