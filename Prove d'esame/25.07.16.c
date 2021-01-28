#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct nodo {
	int key;
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

void in_visit (struct nodo* testa, int* A, int *i) {
	if (testa != NULL) {
		in_visit (testa->left, A, i);
		A[*i]=testa->key;
		(*i)++;
		in_visit(testa->right, A, i);
	}	
}



int main() {

int n, j, val, i;
i=0;
//numero di elementi da inserire nell`ABR
scanf ("%d", &n);
int *A= malloc (sizeof(int)*n);
struct nodo* head=NULL;
 
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	head=Insert (head, val);
}


in_visit(head, A, &i); 

//stampa array 

i=n/2;
printf ("%d \n", A[i]);

return 0;
}


