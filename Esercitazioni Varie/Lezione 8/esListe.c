#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct elem {
	int key;
	struct elem *next;
}; 

struct elem* inserisciintesta (struct elem* testa, int val) {

    struct elem* new=malloc(sizeof(struct  elem));
	 new->key=val;    
	 new->next=NULL;
	
	 if (testa==NULL) {
		testa=new;
		return testa;
	}
		
	 struct elem* p=testa;
	 while (p->next!=NULL) {
		p=p->next;
	 }
		
	 p->next=new;
	 return testa;
}

void stampa(struct elem* testa) {
	struct elem* temp=testa;

		while (temp!=NULL) {
			printf ("%d \n", temp->key);
			temp=temp->next;
		}
}

int main () {

//dichiarazione di una lista, lista e` un puntatore al primo elemento della lista.
struct elem* lista=NULL;
lista=inserisciintesta (lista, 100);
lista=inserisciintesta (lista,200);
lista=inserisciintesta (lista,300);
stampa(lista);


return 0;
}
