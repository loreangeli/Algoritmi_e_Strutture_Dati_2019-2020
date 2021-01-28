#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct _nodo {
	int key;
	int min;
	int cmax;
	struct _nodo* left;
	struct _nodo* right;
} nodo;


nodo* insert(nodo* T, int val) {
	nodo* prec=NULL;
	nodo* new=malloc(sizeof(nodo));
	new->key=val;
	new->left=NULL;
	new->right=NULL;
	new->min=0;
	new->cmax=0;
	//albero vuoto
	if (T==NULL) {
		T=new;
		return T;
	}
	else {
		nodo* temp=T;
		while (temp!=NULL) {
			prec=temp;
			if (val<temp->key)
				temp=temp->left;
			else temp=temp->right;
		}

	}
	if (val<prec->key)
		prec->left=new;
	else prec->right=new;
	
return T;
}


void in_visit(nodo* T) {
	if (T!=NULL) {
		in_visit(T->left);
		printf("%d ",T->key);
		in_visit(T->right);
	}
}


nodo* sommamax(nodo* T) {
	int min;
	if (T==NULL) {
		nodo* S=malloc(sizeof(nodo));
		S->min=INT_MAX;
		S->cmax=0;
		return S;
	}
	/*
	if (T->left==NULL && T->right==NULL) {
		T->min=T->key;
		T->cmax=T->key;
		return T;	
	}
	*/
	nodo* s1=NULL;
	nodo* s2=NULL;
	s1=sommamax(T->left);
	s2=sommamax(T->right);
	
	if (s1->cmax>s2->cmax) {
		T->cmax=T->key+s1->cmax;
		if (T->key > s1->min)
			T->min=s1->min;
		else T->min=T->key;

		return T;
	}
	else if (s1->cmax < s2->cmax) {
		T->cmax=T->key+s2->cmax;
		if (T->key > s2->min)
			T->min=s1->min;
		else T->min=T->key;

		return T;
	}
	else {
		T->cmax=T->key+s1->cmax;		
		if (s1->min < s2->min)
			min=s1->min;
		else min=s2->min;
		if (T->key < min)
			T->min=T->key;
		else T->min=min;
	
		return T;
	}
}



int main() {
int N, val;
scanf("%d", &N);
if (N<1) {
	printf("0");
	return 0;
}
nodo* T= NULL;

for (int i=0;i<N;i++) {
	scanf("%d", &val);
	T=insert(T, val);
}

nodo* sol=sommamax(T);

printf("%d \n", sol->min);



return 0;
}

