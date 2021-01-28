#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
	struct _nodo* next;
	int key;
} nodo;


nodo* Accesso(nodo* testa, int x, int N, int* nelem) {
	//LISTA VUOTA
	if (testa==NULL) {
		//creo nodo
		nodo* new=malloc(sizeof(nodo));
		new->next=NULL;
		new->key=x;
		testa=new;
		*nelem=1;
		return testa;
	}

	
	
	//1
	nodo* q=NULL;
	nodo* p=NULL;
	nodo* s=NULL;
	nodo* temp=testa;
		
	while (temp!=NULL && temp->key != x ) {
		p=temp;
		temp=temp->next;
	}
	if (temp!=NULL)
	s=temp->next;

	//2
	if (temp!=NULL && temp->key==x) {
		//se l`elemento e` gia` in testa non faccio niente, altrimenti:
		if (temp!=testa) {
			q=testa;
			testa=temp;
			temp->next=q;
			p->next=s;
		}		
	}	
	//3
	else {
		//creo nodo
		nodo* new=malloc(sizeof(nodo));
		new->next=NULL;
		new->key=x;

		p=testa;
		testa=new;
		new->next=p;
		//4. rimuovo l`elemento in coda a Q
		if (*nelem + 1 > N) {
			p=NULL;
			s=NULL;
			temp=testa;

			while(temp->next!=NULL) {
				p=temp;
				temp=temp->next;	
			}
			p->next=NULL;
			free(temp);
		}
		else {
			*nelem= *nelem + 1;
		}
	}//chiudo else
	
	return testa;	
}


void Stampa(nodo* testa) {
	nodo* temp=testa;
	
	while(temp!=NULL) {
		printf("%d ", temp->key);
		temp=temp->next;
	}
	
	printf("$ \n");
}


int main() {


int N, e, val, nelem;
nelem=0;
scanf("%d", &N);

nodo* testa=NULL;

scanf("%d", &e);

while (e!=0) {
	if (e==1) {
		scanf("%d", &val);
		testa=Accesso(testa, val, N, &nelem);
	}
	else if (e==2)
		Stampa(testa);

	scanf("%d", &e);
}




return 0;
}
