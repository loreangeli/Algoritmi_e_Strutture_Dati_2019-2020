/* Esame 27.06.14 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	struct _node* next;
	char* nome;
	char* cellulare;
} item;


void print (item** T, int N) {
int i=0;
	for (i=0;i<2*N;i++) {
		item* temp=T[i];
		printf("[%d] ", i);
		while (temp!=NULL) {
			printf("[%s ", temp->nome);
			printf("%s]", temp->cellulare);
			temp=temp->next;
		}
		printf("\n");
	}
}

void printK (item** T, int N, int K) {
	item* temp=T[K];
		while (temp!=NULL) {
			printf("%s ", temp->nome);
			printf("%s", temp->cellulare);
			temp=temp->next;
		printf("\n");
	   }
}

item** insert (item** T, int N, char* nome, char* cellulare) {
	item* nodo=malloc(sizeof(item));
	nodo->nome=malloc(sizeof(char)*101);
	nodo->cellulare=malloc(sizeof(char)*21);
	strcpy(nodo->nome, nome);
	strcpy(nodo->cellulare, cellulare);
	nodo->next=NULL;

	int dim=strlen(nome);
	int sum=0;
	unsigned int c;

	for (int i=0;i<dim;i++) {
		c=nome[i];
		sum=sum+c;
	}
	int hash=sum % (2*N);
	item* temp= T[hash];
	//lista vuota
	if (temp==NULL) {
		T[hash]=nodo;
		return T;
	}
	//lista non vuota
	else {
		temp=T[hash];
		item* prec=NULL;
		while (temp!=NULL && strcmp(temp->nome, nome)<0) {
			prec=temp;
			temp=temp->next;
		}
		if (temp!=NULL && prec!=NULL) {
			prec->next=nodo;
			nodo->next=temp;
			return T;
		}
		if (temp==NULL && prec!=NULL) {
			prec->next=nodo;
			return T;
		}
		if (temp!=NULL && prec==NULL) {
			nodo->next=T[hash];
			T[hash]=nodo;
			return T;
		}
		
	}//chiudo else

return T;

}


int main() {
int N, i, K;
char* nome;
char* cellulare;

scanf("%d", &N);
//creo e inizializzo tabella hash
item** T= malloc(sizeof(item*)*2*N);
for (i=0;i<2*N;i++)
	T[i]=NULL;

for (i=0;i<N;i++) {
	nome=malloc(sizeof(char)*101);
	cellulare=malloc(sizeof(char)*21);
	scanf("%s", nome);
	scanf("%s", cellulare);
	insert(T, N, nome, cellulare);
}

scanf("%d", &K);
//print(T, N);
printK(T, N, K);


//free
free(nome);
free(cellulare);
//deallocazione della memoria della tabella hash
for (i=0;i<2*N;i++) {
	item* temp=T[i];
	item* succ=T[i];
	while (temp!=NULL) {
		succ=temp->next;
		free(temp->nome);
		free(temp->cellulare);
		free(temp);
		temp=succ;
	}
}


free(T);

return 0;
}
