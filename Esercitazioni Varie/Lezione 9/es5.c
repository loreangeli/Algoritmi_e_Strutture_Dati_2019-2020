#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct nodo {
	int key;
	struct nodo *left;
	struct nodo* center;
	struct nodo *right;
}; 


struct nodo* Insert (struct nodo* testa, int val) {
	//creo nodo
	struct nodo* new= malloc (sizeof(struct nodo));
	new->key=val;
	new->left=NULL;
	new->center=NULL;
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
		if (val<current->key)
			current=current->left;
		else if (val % current->key == 0)
			current=current->center;
		else current=current->right;
	}

	if (val<parent->key) parent->left=new;
	else if (val % parent->key == 0) parent->center=new;
	else parent->right=new;

	return testa;
}


int visita(struct nodo* root){
    int h1,h2,h3;
    if (root==NULL)
        return 0;
    h1 = visita(root->left);
    h2 = visita(root->center);
    h3 = visita(root->right);
    if (root->left != NULL && root->center != NULL && root->right != NULL)
        return h1+h2+h3+1;
    else
        return h1+h2+h3;
}


int main() {

int n, j, val;

scanf ("%d", &n);

struct nodo* albero=NULL;
 
//riempi albero
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	albero=Insert (albero, val);
}

int ris= visita(albero);
printf ("%d", ris);

return 0;
}


