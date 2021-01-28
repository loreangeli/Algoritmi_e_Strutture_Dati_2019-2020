#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

int n1, n2;
int val;

//inizializzazione a1
scanf ("%d", &n1);
int a1[n1];

for (int i=0;i<n1;i++) {
	scanf("%d", &val);
	a1[i]=val;
}

//inizializzazione a2
scanf ("%d", &n2);
int a2[n2];

for (int i=0;i<n2;i++) {
	scanf("%d", &val);
	a2[i]=val;
}

//programma
int cont=0;
for (int i=0;i<n1;i++) {
	for (int j=0;j<n2;j++) {
		if (a1[i]==a2[j]) {
			cont++;
		}
	}
}

printf("%d", cont);

return 0;
}
