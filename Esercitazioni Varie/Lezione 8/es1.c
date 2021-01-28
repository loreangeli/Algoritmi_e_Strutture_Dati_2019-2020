#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct elem {
	int key;
	struct elem *next;
}; 

struct elem* inserisciintesta (struct elem* testa, struct elem** coda, int val) {

    struct elem* new=malloc(sizeof(struct  elem));
	 new->key=val;    
	 new->next=NULL;
	
	 if (testa==NULL) {
		testa=new;
		*coda=testa;
		return testa;
	}
		
	(*coda)->next=new;
	*coda=(*coda)->next;

	 return testa;
}

void stampa(struct elem* testa) {
	//printf ("STAMPA: \n");
	
	struct elem* temp=testa;

		while (temp!=NULL) {
			printf ("%d \n", temp->key);
			temp=temp->next;
		}
}

void stampaalcontrario (struct elem* testa) {
		if (testa==NULL)
			return;

		stampaalcontrario (testa->next);
		printf ("%d \n", testa->key);
}

int main () {

int val;
int n;
int i;
//dichiarazione di una lista, lista e` un puntatore al primo elemento della lista.
struct elem* head=NULL;
struct elem* coda=NULL;

scanf ("%d", &n);

for (i=0;i<n;i++) {
	scanf ("%d", &val);
	head=inserisciintesta (head, &coda, val);
}

stampaalcontrario (head);

return 0;
}
