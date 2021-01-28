#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct elem {
	int key;
	struct elem *next;
	struct elem *prev;
}; 

struct elem* inserisciintesta (struct elem* testa, struct elem** coda, int val) {

    struct elem* prec=NULL;
    struct elem* new=malloc(sizeof(struct  elem));
	 new->key=val;    
	 new->next=NULL;
	 new->prev=NULL;

	 if (testa==NULL) {
		testa=new;
		*coda=testa;
		return testa;
	}
		
	(*coda)->next=new;
	prec=*coda;
	*coda=(*coda)->next;
	(*coda)->prev=prec;

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

void stampacontrariomultidirezionale (struct elem* coda) {
	struct elem* p=coda;
	
	while (p != NULL) {
   	printf ("%d \n", p->key);
		p=p->prev;
	}

}

//stampa posizione del valore se presente, se val non presente ritorna -1
int funzione (struct elem** testa, int val) {

	struct elem* p=(*testa);
	struct elem* prec=p;
	struct elem* succ=NULL;

	int cont=0;	
	while (p!=NULL) {
		//elemento val trovato nella lista, prima sposta il nodo in cima e dopo restituisci la posizione di val in lista
		if (p->key==val) {
			//val e` il primo elemento 
			if (p==prec) {
				return cont;
			}
			succ=p->next;
			prec->next=succ;
			p->next=*testa;
			(*testa)=p;

			return cont;
		}
		//elemento non trovato
		cont++;
		prec=p;
		p=p->next;	
	}
	
	//elemento non presente in lista
	return -1;
}


int main () {

int val;
int n;
int j;
int i; 
int ris;
//dichiarazione di una lista, lista e` un puntatore al primo elemento della lista.
struct elem* head=NULL;
struct elem* coda=NULL;

scanf ("%d", &n);

//inserisci elementi nella lista
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	head=inserisciintesta (head, &coda, val);
}

//printf ("Stampa lista iniziale: \n");
//stampa (head);
//printf ("Fine stampa lista iniziale: \n");

do {
scanf ("%d", &i);
ris=funzione (&head, i);
printf ("%d \n", ris);
}

while (ris!=(-1)); 


return 0;
}
