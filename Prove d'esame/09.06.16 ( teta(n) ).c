#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct nodo {
	int key;
	char stringa [101];
	struct nodo *left;
	struct nodo *right;
}; 


struct nodo* Insert (struct nodo* testa, int val) {
	//creo nodo
	struct nodo* new= malloc (sizeof(struct nodo));
	new->key=val;
	new->left=NULL;
	new->right=NULL;

		//inserisco nodo
	//albero vuoto
	if (testa==NULL) {
		testa=new;
		return testa;	
	}
	//altrimenti
	struct nodo* parent;
	struct nodo* current= testa;
	while (current!=NULL) {
		parent=current;
		if (current->key < val)
			current=current->right;
		else current=current->left;
	}

	if (parent->key < val) parent->right=new;
	else parent->left=new;

	return testa;
}


void print(struct nodo* testa, int* A, int *i) {
	if (testa != NULL) {
		print(testa->left, A, i);
		A[*i]=testa->key; (*i)++;
		print(testa->right, A, i);
	}
}


int main() {

int N, i, valore, j;
scanf("%d", &N);
int* A= malloc (sizeof(int)*N);

struct nodo* head=NULL;

for (i=0;i<N;i++) {
	A[i]=0;
	scanf("%d", &valore);
	head=Insert (head, valore);
}

j=0;
print (head, A, &j);
printf("%d", A[N-2]);

return 0;
}

