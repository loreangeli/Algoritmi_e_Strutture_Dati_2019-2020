#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

//numero di stringhe
int N; int i=0; int j=0;

char* temp=(char *) malloc (101 * sizeof(char));
scanf("%d", &N);
//inizializzo array di stringhe
char **a=(char **) malloc(N * sizeof(char*)); 
//inizializzo le celle dell`array
for (i=0;i<N;i++) {
	a[i]=(char*) malloc (101 * sizeof(char));
//inserisci elemento nell`array
	scanf("%s", a[i]);
}

//STAMPA ARRAY PRIMA DELL`ORDINAMENTO
//for (i=0;i<N;i++)
//	printf("%s \n", a[i]);


//algoritmo insertion sort su stringhe IL MIO
for (j=1;j<N;j++) {
	i=j-1;
	temp=a[j];

	while ((i>0) && ( strcmp(a[j],a[i])<0 )) {
			a[i+1]=a[i];
			i=i-1;
	}
	a[i+1]=temp;
}

//STAMPA ARRAY ORDINATO
//printf("stampa array ordinato \n");
for (i=0;i<N;i++)
	printf("%s \n", a[i]);
//rilascia la memoria
for (i=0;i<N;i++)
	free(a[i]);

free(a);

return 0;
}
