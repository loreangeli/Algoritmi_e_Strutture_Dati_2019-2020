#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 
  !!!!!!!!!!!! D A  F A R E !!!!!!!!!!!!
  sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array mentre 
  px è la posizione dell'elemento perno.
  La funzione deve restituire la posizione del perno dopo che gli elementi sono 
  stati partizionati.
*/
int distribuzione(char **a, int sx, int px, int dx) { 
	char temp[101];
	char x[101];
	strcpy(x, a[px]);

	int j;
	int i=sx-1;

	for (j=sx;j < dx; j++) {
		if (strcmp(a[j],x) <= 0) {
			i++;
			strcpy(temp, a[i]);
			strcpy(a[i], a[j]);
			strcpy(a[j], temp);
		}
	}

	strcpy(temp, a[i+1]);
	strcpy(a[i+1], a[dx]);
	strcpy(a[dx], temp);

	return i+1;
}

void quicksort( char **a, int sx, int dx ) {
  
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
  
  int i,len;
  scanf("%d", &len);
  char **A=(char **) malloc(len * sizeof(char*));

  for( i = 0; i < len; i++ ) {
	  A[i]=(char *) malloc (101 * sizeof(char));
	  scanf("%s", A[i]);
	}  

  quicksort(A, 0, len-1);
  
  /* Stampa l'array ordinato */
  for( i = 0; i < len; i++ ) 
    printf("%s \n", A[i]);
	
  return 0;
}
