#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

int dim1=0; 
int i=0; 
int max=0;
int somma=0;


scanf("%d", &dim1);
int *a1=(int *) malloc(dim1 * sizeof(int)); 
//inserisci elementi nel primo array
for (i=0;i<dim1;i++) {
	scanf("%d", &a1[i]);
}

max=0;
somma=0;

for (i=0;i<dim1;i++) {
	if (somma>0) somma=somma+a1[i];
	else somma=a1[i];

	if (somma>max) max=somma;
}

//stampa array ordinato
	printf("%d", max);



return 0;
}
