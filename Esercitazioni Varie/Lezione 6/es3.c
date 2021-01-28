#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct punto {
	int x;
	int y;
};


int confronta (const void *a, const void *b) {
	struct punto *A= (struct punto*) a;
	struct punto *B=(struct punto*) b;	

	//caso in cui la x sia uguale per tutte e due le coppie
	if (A->x == B->x) {
		if (A->y == B->y) return 0; 
		if (A->y < B->y) return +1;
		return -1;
	}
	//caso in cui la prima x della prima coppia sia piu` piccola della x della 	//seconda coppia	
	if (A->x < B->x) return -1;
	//altrimenti, la y della seconda coppia e` maggiore della x della prima coppia
	return +1;
}


int main () {

int DIM; int i; 
scanf ("%d", &DIM);	

struct punto *A= malloc (sizeof(struct punto*) * DIM);

for (i=0;i<DIM;i++) {
	scanf ("%d", &A[i].x);
	scanf ("%d", &A[i].y);
}

qsort (A, DIM, sizeof(struct punto*), confronta);

for (i=0;i<DIM;i++) {
	printf ("%d ", A[i].x);
	printf ("%d \n", A[i].y);
}


return 0;
}
