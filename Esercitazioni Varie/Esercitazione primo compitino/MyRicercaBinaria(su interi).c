#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RicercaBinaria(int A[], int k, int sx, int dx) {
	if (sx > dx) return -1;
	if (sx==dx) {
		if (A[sx]==k) return sx;
		else return -1;
	}
		int cx= (sx+dx)/2;
		if (A[cx]==k) { 
			return cx;
		}
		if (A[cx]>k){
			return RicercaBinaria(A, k, sx, cx-1);
		}
		else {
		return RicercaBinaria(A, k, cx+1, dx);
		}
}


int main() {

int N, k, i;
printf("Inserisci dimensione \n");
scanf("%d", &N);

int A[N];

printf("Inserisci elementi nell`array: \n");
for (i=0;i<N;i++)
	scanf("%d", &A[i]);
printf("Inserisci elemento da cercare: \n");
scanf("%d", &k);

int a=RicercaBinaria(A,k,0,N-1);
	
	printf("k si trova all`indice %d",a);

return 0;
}
