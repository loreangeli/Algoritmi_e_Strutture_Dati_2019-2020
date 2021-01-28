#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//"head" punta alla testa della lista
//"coda" punta alla coda della lista

struct elem {
	int key;
	struct elem *next;
}; 


struct elem* Insert (struct elem* testa, struct elem** coda, int val) {

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
	
	struct elem* temp=testa;

		while (temp!=NULL) {
			printf ("%d ", temp->key);
			temp=temp->next;
		}
}

int media(struct elem* testa, int n) {
	int m=0;
	struct elem* temp=testa;

		while (temp!=NULL) {
			m=m+(temp->key);
			temp=temp->next;
		}
	m=m/n;
	return m;
}


struct elem* Remove (struct elem** testa, int m) {

if (*testa == NULL) return *testa;
struct elem* prec=NULL;
struct elem* succ=(*testa)->next;
struct elem* p=*testa;


	while (p!=NULL) {
		//se la chiave e` minore o uguale della media
		if ( (p->key) <= (m) ) {
					//primo elemento da eliminare
					if (p==*testa) {
						*testa=succ;	
						free(p);

						succ=succ->next;
						p=*testa;
					}
					//ultimo elemento da eliminare
					else if (succ==NULL) {
						prec->next=NULL;
						free(p);

						p=NULL;
						return *testa;
					}
					//elemento di mezzo da eliminare
					else {
						free(p);
						prec->next=succ;

						p=succ;
						succ=p->next;
					}		
		} 
	
		if ((p->key) > (m)) {
			prec=p;
			p=p->next;
			if (p!=NULL)
			succ=p->next;
		}	

	}

return *testa;

}


int main() {

int n, j, val;

scanf ("%d", &n);

struct elem* lista=NULL;
struct elem* coda=NULL;

//riempi albero
for (j=0;j<n;j++) {
	scanf ("%d", &val);
	lista=Insert (lista, &coda, val);
}

int m= media(lista,n);
printf ("%d \n", m);
stampa (lista);
Remove (&lista, m);
printf ("\n");
stampa (lista);


return 0;
}

