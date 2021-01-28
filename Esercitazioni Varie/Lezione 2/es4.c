#include <stdio.h>
#include <string.h>


int anagramma (unsigned char* s1, unsigned char *s2) {
	int i=0;
	int xlen=strlen(s1);
	int ylen=strlen(s2);	
	if (xlen != ylen) return 0;

	char xc[256];
	char yc[256];
	//azzero gli array
	for (int i=0;i<256;i++) {
		xc[i]=0;
		yc[i]=0;
	}
		
	//copio la stringa s1 e s2 negli array xc e yc
	for (int j=0;j<xlen;j++) {
		xc[*(s1+j)]=xc[*(s1+j)]+1;
		yc[*(s2+j)]=yc[*(s2+j)]+1;
	}

	for (int h=0;h<256;h++)
		if (xc[h]!=yc[h])
			return 0;

	return 1;
}


int main() {

unsigned char s1[256];
unsigned char s2[256];

scanf("%s", s1);
scanf("%s", s2);

int ris=anagramma(s1, s2);

printf("%d", ris);










return 0;
}
