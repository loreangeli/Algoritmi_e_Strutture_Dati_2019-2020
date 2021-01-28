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

int cerca (struct nodo* testa, int val) {
	struct nodo* p=testa;
	int altezza=0;

	while (p != NULL) {
		if (p->key == val)	
			return altezza;
		if (val < p->key) {
			p=p->left;
			altezza++;
		}
		else {
			p=p->right;
			altezza++;
		}
	}

	return -1;
}



int main() {

int n, j, val, i, ris;

scanf ("%d", &n);
struct nodo* head=NULL;
 
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	head=Insert (head, val);
}

do {
	scanf ("%d", &i);
	ris=cerca (head, i);

	if ( i>=0 && (ris != -1) ) {
		printf ("%d \n", ris);
	}
	if (i>=0 && (ris == -1) ) 
		printf("NO \n");
}
while (i >= 0);


return 0;
}


