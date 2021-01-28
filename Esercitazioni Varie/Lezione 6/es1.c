#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int confrontaInt (const void *a, const void *b) {
	

if ( ( *(int*)a < *(int*)b ) && ( *(int*)a%2!=0 && *(int*)b%2!=0 ) )
	return (1);

if ( ( *(int*)a > *(int*)b ) && ( *(int*)a%2!=0 && *(int*)b%2!=0 ) )
	return (-1);

if ( ( *(int*)a < *(int*)b ) && ( *(int*)a%2==0 && *(int*)b%2==0 ) )
	return (-1);

if ( ( *(int*)a > *(int*)b ) && ( *(int*)a%2==0 && *(int*)b%2==0 ) )
	return (1);

if ( ( *(int*)a%2==0 && *(int*)b%2!=0 ) ) 
	return (-1);

if ( ( *(int*)a%2!=0 && *(int*)b%2==0 ) ) 
	return (1);

return 0;

}



int main () {

int DIM; int i; 
scanf ("%d", &DIM);	

int *A=(int*) malloc (sizeof(int) * DIM);

for (i=0;i<DIM;i++)
	scanf ("%d", &A[i]);

qsort (A, DIM, sizeof(int), confrontaInt);

for (i=0;i<DIM;i++)
	printf ("%d \n", A[i]);


return 0;
}
