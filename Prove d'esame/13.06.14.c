//Esame 13.06.14

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct  _esame {
	char* sigla;
	int crediti;
	int difficolta;

} esame;

typedef struct  __sigla {
	char* sigla;

} _sigla;


void print(esame* A, int N) {
	for (int i=0;i<N;i++) {
		printf("%s ", A[i].sigla);
		printf("%d ", A[i].crediti);
		printf("%d \n", A[i].difficolta);
	}
}

void printB(_sigla* B, int dimB) {
	for (int i=0;i<dimB;i++)
		printf("%s \n", B[i].sigla);
}


void insert(esame* A, int N, char* sigla, int crediti, int difficolta, int i) {
	A[i].sigla=malloc(sizeof(char)*101);
	strcpy(A[i].sigla, sigla);
	A[i].crediti=crediti;
	A[i].difficolta=difficolta;
}

int compare1(const void* a, const void* b) {
	const esame* A= a;
	const esame* B=b;
	//crediti diversi
	if (A->crediti < B->crediti) 
		return +1;
	if (A->crediti > B->crediti)
		return -1;
	//parita di crediti
	if (A->crediti == B->crediti) {
		//difficolta
		if (A->difficolta < B->difficolta)
			return -1;
		if (A->difficolta > B->difficolta)
			return +1;
		//pari difficolta
		if (A->difficolta == B->difficolta) {
			if (strcmp(A->sigla, B->sigla)<0)
				return -1;
			if (strcmp(A->sigla, B->sigla)>0)
				return +1;
		}
	}//chiudoif
	
return 0;
}

int compare2(const void* a, const void* b) {
	const _sigla* A= a;
	const _sigla* B=b;
	if (strcmp(A->sigla,B->sigla)<0)
		return -1;
	else return +1;
	
}


int costruisciB(esame* A, int N, int K, _sigla* B, int dimB) {
	int cont=0;
	for (int i=0;i<N;i++) {
		if (cont<K) {
		cont=cont+A[i].crediti;	
				
		if (cont<=K) {
			B[dimB].sigla=malloc(sizeof(char)*101);
			strcpy(B[dimB].sigla, A[i].sigla);
			dimB++;
		}
		
		if (cont>K)
			cont=cont-A[i].crediti;			
		}
	}

return dimB;
}


int main() {

int K,N, crediti, difficolta, dimB;
char* sigla= malloc(sizeof(char)*101);


scanf("%d", &K);
scanf("%d", &N);

dimB=0;
esame* A= malloc(sizeof(esame)*N);
_sigla* B=malloc(sizeof(_sigla)*N);

for (int i=0;i<N;i++) {
	scanf("%s", sigla);
	scanf("%d", &crediti);
	scanf("%d", &difficolta);
	insert(A, N, sigla, crediti, difficolta, i);
}

qsort(A, N, sizeof(esame), compare1);
dimB=costruisciB(A, N, K, B, dimB);
qsort(B, dimB, sizeof(_sigla), compare2);
printB(B, dimB);

return 0;
}
