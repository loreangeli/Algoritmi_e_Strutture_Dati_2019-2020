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


struct nodo* lca (struct nodo* testa, int x, int y) {
	if (testa == NULL) return NULL;
	if (x < testa->key && y < testa->key) 
		return lca (testa->left, x, y);	
	if (x > testa->key && y > testa->key)
		return lca (testa->right, x, y);

	return testa;
}

void print(struct nodo* testa, int* A, int *i) {
	if (testa != NULL) {
		print(testa->left, A, i);
		A[*i]=testa->key; (*i)++;
		print(testa->right, A, i);
	}
}


void free_tree(struct nodo* root) {
    if(root == NULL)
        return;
    /* Deallocazione del figlio sinistro */
    if(root->left != NULL)
        free_tree(root->left);
    /* Deallocazione del figlio destro */
    if(root->right != NULL)
        free_tree(root->right);
    /* Deallocazione del nodo corrente */

    free(root);
}


int main() {

int N, i, valore, x, y;
scanf("%d", &N);

struct nodo* head=NULL;

for (i=0;i<N;i++) {
	scanf("%d", &valore);
	head=Insert (head, valore);
}

scanf("%d", &x);
scanf("%d", &y);

struct nodo* temp=NULL;

temp=lca (head, x, y);
printf("%d", temp->key);

//deallocazione
free_tree (head);

return 0;
}

