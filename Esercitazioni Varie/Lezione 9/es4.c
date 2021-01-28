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


void stampaordinata(struct nodo* testa) {
	if (testa == NULL) return;

	stampaordinata (testa->left);
	printf ("%d \n", testa->key);
	stampaordinata (testa->right);
}


int confronto (struct nodo* p, struct nodo* q, int k) {
	while ( ((p->key) == (q->key)) && ((p->key) != k) && ((q->key) != k) ) {
		if (k<p->key) p=p->left;
		else p=p->right;
		if (k<q->key) q=q->left;
		else q=q->right;
	}

	if (p->key == q->key)
		return 1;
	else return 0;
}

int main() {

int n, j, val, k, ris;

scanf ("%d", &n);
scanf ("%d", &k);

struct nodo* albero1=NULL;
struct nodo* albero2=NULL;
 
//riempi albero1
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	albero1=Insert (albero1, val);
}
//riempi albero2
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	albero2=Insert (albero2, val);
}

ris = confronto (albero1, albero2, k);
printf ("%d", ris);

return 0;
}


