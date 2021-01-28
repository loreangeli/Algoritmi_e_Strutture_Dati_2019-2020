#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

int dim1=0; 
int i=0; 
int j=0; 
int min=0;
int temp=0;


scanf("%d", &dim1);
int *a1=(int *) malloc(dim1 * sizeof(int)); 
//inserisci elementi nel primo array
for (i=0;i<dim1;i++) {
	scanf("%d", &a1[i]);
}

//selection sort
for (i=0;i<dim1;i++) {
	min=i+1;
	for (j=i+1;j<dim1;j++) {
		if (a1[j]<a1[i] && a1[j]<a1[min]) 
			min=j;
	}	
	
	if (a1[min]<a1[i] && min<dim1) {
			temp=a1[min];
			a1[min]=a1[i];
			a1[i]=temp;
	}
	
}

//stampa array ordinato
for (i=0;i<dim1;i++)
	printf("%d \n", a1[i]);



return 0;
}
