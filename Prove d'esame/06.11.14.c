//Esame 06.11.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node {
  struct node* next;  
  char* nome;
  int valore;
} item;


typedef struct _coppia {
	char* nome;
	int valore;
} coppia;


item** insert (item** T, char* X, int valore ,int N) {
	//creo oggetto
	item* nodo=malloc (sizeof(item));
	nodo->nome=malloc (sizeof(char)*101);
	strcpy(nodo->nome, X);
	nodo->valore=valore;
	nodo->next=NULL;

	int size=strlen (nodo->nome);
   int sum=0;

   for (int i=0;i<size;i++) {
     unsigned int ch=nodo->nome[i];
     sum=sum+ch;	
   }
   int hash=sum % (2*N);
	item* temp=T[hash];
   //inserimento caso uno
   if (T[hash]==NULL) {
  		T[hash]=nodo;
		return T;
	}
	//caso due/tre
	else {
		while (temp!=NULL) {
				if (strcmp(temp->nome, X)==0) {
					if (valore <= temp->valore)
						return T;
					else if (valore>temp->valore) {
						temp->valore=valore;
						return T;	
					}
				}//chiudo if
			temp=temp->next;		
		}//chiudowhile

	}//else
		//lista non vuota, inserimento in testa
		if (temp==NULL) {
			temp=T[hash];
			nodo->next=T[hash];
			T[hash]=nodo;
			return T;
		}

	return T;
}

void print (item** T, int n) {
	int i;
	printf ("STAMPA: \n");
	//struct item** p=T;

	for (i=0;i<2*n;i++) {
		item* c=T[i];
		printf ("%d -> ", i);
		if (c == NULL)
			printf ("NULL ");
		while (c != NULL) {
			
			printf ("[%d ", c->valore);
			printf("%s]", c->nome);
			c=c->next;
		}
		printf ("\n");
	}
}


int converthashtoarray(item** T, int N, coppia* A) {
int cont=0;

	for (int i=0;i<2*N;i++) {
		item* punt=T[i];
		while (punt!=NULL) {
			A[cont].nome=malloc(sizeof(char)*101);
			strcpy(A[cont].nome, punt->nome);
			A[cont].valore=punt->valore;
			punt=punt->next;
			cont++;
		}
	}

return cont;
}


void stampaA (coppia* A, int dimA) {
int i;
	for (i=0;i<dimA;i++) {
		printf("%s ", A[i].nome);
		printf("%d \n", A[i].valore);	
	}

}


int compare (const void *a, const void *b) {
	const coppia* A= a;
	const coppia* B= b;
	
	if (A->valore < B->valore)
		return +1;
	if (A->valore > B->valore)
		return -1;
	else if (A->valore == B->valore) {
		if (strcmp(A->nome, B->nome)<0)
			return -1;
		else return +1;
	}

	return 0;
}


int main() {

int N, i, valore;
scanf("%d", &N);
item** T= (item **) malloc (2*N*sizeof(item*));
//inizializzo T a NULL
for (i=0;i<N;i++) {
	T[i]=NULL;
}

for (i=0;i<N;i++) {
  char* nome=malloc(sizeof(char)*101);
  scanf("%s", nome);
  scanf("%d", &valore);
  T=insert(T, nome, valore, N);
}

coppia* A=malloc (sizeof(coppia)*N);
int dimA=converthashtoarray(T, N, A);
//stampaA(A, dimA);
qsort(A, dimA, sizeof(coppia), compare);


for (i=0;i<dimA && i<15;i++)
	printf("%s \n", A[i].nome);


return 0;
}


