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


int max(int sx, int dx) {
	if (sx<dx) return dx;
	else return sx;
}


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

int altezza (struct nodo* testa) {
	if (testa == NULL)
		return 0;
	else  {
		int sx=altezza (testa->left);
		int dx=altezza (testa->right);
		return max(sx, dx)+1;
	}
}



int main() {

int n, j, val;

scanf ("%d", &n);
struct nodo* head=NULL;
 
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	head=Insert (head, val);
}
 printf ("%d", altezza (head));

return 0;
}


