#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

int dim1=0;
int dim2=0; 
int i=0; 
int j=0;
int h=0;

scanf("%d", &dim1);
int *L=(int *) malloc((dim1+1) * sizeof(int)); 
//inserisci elementi nel primo array
for (i=0;i<dim1;i++) {
	scanf("%d", &L[i]);
}

scanf("%d", &dim2);
int *R=(int *) malloc((dim2+1) * sizeof(int)); 
L[dim1]=100000;
R[dim2]=100000;

int *A=(int *) malloc((dim1+dim2) * sizeof(int));
//inserisci elementi nel secondo array
for (i=0;i<dim2;i++) {
	scanf("%d", &R[i]);
} 


i=0;
j=0;
for (j=0;j<(dim1+dim2);j++) {
	if (L[i]<R[h]) {
		A[j]=L[i];
		i++;
	}
	else {
		A[j]=R[h];
		h++;
	}	
}
//stampa array
for (i=0;i<(dim1+dim2);i++) 
	printf("%d \n", A[i]);


return 0;
}
