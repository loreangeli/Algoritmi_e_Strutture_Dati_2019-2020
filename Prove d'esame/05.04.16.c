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

struct nodo* Insert (struct nodo* testa, char* stringa, int val) {
	//creo nodo
	struct nodo* new= malloc (sizeof(struct nodo));
	new->key=val;
	strcpy(new->stringa, stringa);
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
		if ( strcmp(current->stringa, stringa) < 0)
			current=current->right;
		else current=current->left;
	}

	if (strcmp(parent->stringa, stringa) < 0)
	 parent->right=new;
	else parent->left=new;

	return testa;
}


void print(struct nodo* testa) {
	if (testa != NULL) {
		print(testa->left);
		printf("%d", testa->key);
		print(testa->right);
	}
}

//ritorna il puntatore al nodo in cui si trova la stringa  
struct nodo* cerca (struct nodo* testa, char* stringa) {
		if (testa == NULL) return NULL;
		if (strcmp(testa->stringa, stringa)==0) 
			return testa;
		if (strcmp(testa->stringa, stringa) < 0)
			return cerca (testa->right, stringa);
		else 
			return cerca (testa->left, stringa);
		
}


//ritorna il massimo elemento dell`albero con radice in testa.
int Max(struct nodo* testa, int* max) {
	if (testa==NULL) return -1;

	Max(testa->left, max);
	Max(testa->right, max);

	if (*max < testa->key) *max=testa->key; 
	
	return *max;
}


int main() {

int N, i, valore;
char *stringa=NULL;
char *stringasearch= malloc (sizeof(char)*101);
scanf("%d", &N);

struct nodo* head=NULL;


for (i=0;i<N;i++) {
	stringa= malloc (sizeof(char)*101);
	scanf("%s", stringa);
	scanf("%d", &valore);
	head=Insert (head, stringa, valore);
	free(stringa);
}


scanf("%s", stringasearch);
struct nodo* p=NULL;
i=-10;

//p punta al nodo che contiene la stringa data in input 
p=cerca(head, stringasearch);

//printf(" \n %d \n", p->key);

int ris=Max (p, &i);
printf("%d", ris);



return 0;
}

