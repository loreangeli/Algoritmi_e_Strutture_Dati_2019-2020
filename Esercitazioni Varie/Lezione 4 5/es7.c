#include <stdio.h>
#include <stdlib.h>

int preordina(int a[], int sx, int dx) { 
	int temp;
	int cont=0;
	int j;
	int i=sx-1;

	for (j=sx;j < dx; j++) {
		if ( (a[j]%2) == 0 ) {
			cont++;
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

if (a[dx]%2==0) cont++;

	temp=a[i+1];
	a[i+1]=a[dx];
	a[dx]=temp;

return cont;
}

int distribuzione(int a[], int sx, int px, int dx) { 
	int temp;
	int x;
	x=a[px];

	int j;
	int i=sx-1;

	for (j=sx;j < dx; j++) {
		if (a[j] <= x) {
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	temp=a[i+1];
	a[i+1]=a[dx];
	a[dx]=temp;

	return i+1;
}

void quicksort( int a[], int sx, int dx ) {
  
  int perno, pivot;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
    pivot = dx;

    perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot] 
					        da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
    
  }

}


int main() {

int N; int *A; int i; int px=0;
scanf("%d", &N);

A= (int*) malloc (N * sizeof(int));

for (i=0;i<N;i++)
	scanf ("%d", &A[i]);

px=preordina (A, 0, N-1);
if (px==N) {
	quicksort (A, 0, N-1);
}
if (px==0) {
	quicksort (A, 0, N-1);
}
else {
quicksort (A, 0, px-1);
quicksort (A, px, N-1);
}


  for( i = 0; i < N; i++ ) 
    printf("%d ", A[i]);
	


return 0;
}
