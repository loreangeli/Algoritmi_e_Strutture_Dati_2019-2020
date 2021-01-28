#include <stdio.h>

int* FindVal (int a[], int len, int val) {
	int *p=NULL;
	for (int i=0;i<len;i++) {
		if (a[i]==val) p=&a[i];
	}

	return p;
}

int main() {
   int x, val;
	int *q;
	int a[10];

	for (int i=0;i<10;i++) {
		scanf("%d", &x);
		a[i]=x;	
	}

	scanf("%d", &val);
q=FindVal(a, 10, val);
	

	
	if (q==NULL) printf("non trovato");
	else printf("trovato");	

return 0;
}

