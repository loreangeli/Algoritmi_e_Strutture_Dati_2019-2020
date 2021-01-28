#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct nodo {
	char stringa [101];
	struct nodo *left;
	struct nodo *right;
}; 

struct nodo* Insert (struct nodo* testa, char* stringa) {
	//creo nodo
	struct nodo* new= malloc (sizeof(struct nodo));
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

struct nodo* m(struct nodo* testa) {
	if (testa->left==NULL && testa->right==NULL)
		return testa;
	struct nodo* current=testa;
	struct nodo* parent;
	while (current != NULL) {
		parent=current;
		current=current->left;
	}
	
	return parent;
}


int prefisso (char* string2, char* string1) {
	int dim1=strlen(string1);
	int dim2=strlen(string2);

	if (dim1>dim2) return -1;

	for (int i=0;i<dim1;i++) {
		if (string1[i] != string2[i])
			return -1;
	}

	return 1;
}


void prefix (struct nodo* testa) {
	struct nodo* string2=NULL;	
	string2= m(testa);
	int ris=prefisso(testa->stringa, string2->stringa);

	if (ris == 1)
		printf("%s \n", testa->stringa);

}

void print (struct nodo* testa) {
	if (testa != NULL) {	
		print(testa->left);
		prefix(testa);
		print(testa->right);
	}
}


int main() {

int N, i;
char *stringa=NULL;

scanf("%d", &N);

struct nodo* head=NULL;


for (i=0;i<N;i++) {
	stringa= malloc (sizeof(char)*101);
	scanf("%s", stringa);
	head=Insert (head, stringa);
	free(stringa);
}

print(head);


return 0;
}

