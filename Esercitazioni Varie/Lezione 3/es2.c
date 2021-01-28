#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

int dim1; int dim2; int i=0; int j=0; int cont=0;


scanf("%d", &dim1);
int *a1=(int *) malloc(dim1 * sizeof(int)); 
//inserisci elementi nel primo array
for (i=0;i<dim1;i++) {
	scanf("%d", &a1[i]);
}
//printf("stampa dimensione: %d \n", dim1);
scanf("%d", &dim2);
//printf("stampa dimensione: %d \n", dim2);
int *a2=(int *) malloc(dim2 * sizeof(int));
//inserisci elementi nel secondo array
for (j=0;j<dim2;j++) {
	scanf("%d", &a2[j]);
}
/*
//stampa elementi primo array
//printf("Elementi primo array");
for (i=0;i<dim1;i++) {
	printf("%d ", a1[i]);
}
//stampa elementi secondo array
//printf("Elementi secondo array");
for (i=0;i<dim2;i++) {
	printf("%d ", a2[i]);
}
*/
i=0; j=0;

while (i<dim1 && j<dim2) {
	if (a1[i] < a2[j]) 
		i++;
	if (a1[i] > a2[j]) 
		j++;
	if (a1[i] == a2[j]) {
		cont++;
		i++;
		j++;
	}
}

printf("%d", cont);
 
return 0;
}
