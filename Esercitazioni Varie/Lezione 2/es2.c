#include <stdio.h>

void reset (int array[], int len) {
	for (int i=0;i<len;i++)
		array[i]=0;
}

void add(int array[], int len, int val) {
	if (val>=0 || val<=len-1) array[val]++;
}


int main() {

int len=10; 
int array[len];
int val;

reset(array, len);

scanf("%d", &val);
while (val!=(-1)) {
	add(array, len, val);
	scanf("%d", &val);	
}

//stampa 
for (int i=0;i<len;i++)
	printf("%d \n",array[i]);
















return 0;
}
