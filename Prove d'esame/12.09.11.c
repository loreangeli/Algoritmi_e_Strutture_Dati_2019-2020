//Esame 12.09.11
//ricorda il qsort funziona solo con array e non puo essere utilizzato con liste!!!!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _nodo {
	char* paziente;
	struct _nodo* next;
} nodo;

nodo* insert(nodo* lista, char* stringa) {
	nodo* new=malloc(sizeof(nodo));
	new->next=NULL;
	new->paziente=malloc(sizeof(char)*101);
	strcpy(new->paziente, stringa);


	nodo* prec=NULL;
	nodo* temp=lista;


	if (lista==NULL) {
		lista=new;
		return lista;
	}
	else {
		while (temp!=NULL) {
			prec=temp;
			temp=temp->next;
		}		
	}

	prec->next=new;
	return lista;	
}


nodo* rimuovi(nodo* lista) {

	if (lista==NULL) {
		return NULL;
	}
	else {
		nodo* temp=lista;
		lista=lista->next;
		free(temp->paziente);
		free(temp);
	}

	return lista;		
}


void print(nodo* lista) {

	nodo* temp=lista;
	while(temp!=NULL) {	
		printf("%s \n", temp->paziente);
		temp=temp->next;
	}

	printf("$ \n");
}

void printA(nodo* A, int cont) {
	for (int i=0;i<cont;i++) {
		printf("%s \n", A[i].paziente);
	}
	printf("$ \n");
}

int compare (const void* a, const void* b) {
	nodo* a1=(nodo*) a;
	nodo* b2=(nodo*) b;

	if (strcmp(a1->paziente, b2->paziente)<0)
		return -1;
	else return +1;
}

int main() {

int e; int cont=0;
nodo* lista=NULL;  

scanf("%d", &e);


while (e!=0) {
	char* stringa=malloc(sizeof(char)*101);
	if (e==1) {
		scanf("%s", stringa);
		lista=insert(lista, stringa);
		cont++;
	}
	else {
		lista=rimuovi(lista);		
		cont--;
	}

scanf("%d", &e);

}

nodo* A=malloc(sizeof(nodo)*cont);
nodo* temp=lista;

int i=0;

while (temp!=NULL && i<cont){
	A[i].paziente=malloc(sizeof(char)*101);
	strcpy(A[i].paziente, temp->paziente);
	temp=temp->next;
	i++;
}

qsort(A, cont, sizeof(nodo), compare);

printA(A, cont);



return 0;
}
