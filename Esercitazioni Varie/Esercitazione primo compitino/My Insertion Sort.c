#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

int dim1; int i=0; 
int j=0; 
int temp=0;

scanf("%d", &dim1);
int *a1=(int *) malloc(dim1 * sizeof(int)); 
//inserisci elementi nel primo array
for (i=0;i<dim1;i++) {
	scanf("%d", &a1[i]);
}

//insertion sort
for (i=1;i<dim1;i++) {
	j=i-1;

	while (j>=0) {
		if (a1[i]<a1[j]) {
			temp=a1[i];
			a1[i]=a1[j];
			a1[j]=temp;
			i--;
		}
	j--;
	}
}

//stampa array ordinato
printf("Array Ordinato \n");
for (i=0;i<dim1;i++)
	printf("%d", a1[i]);



return 0;
}
