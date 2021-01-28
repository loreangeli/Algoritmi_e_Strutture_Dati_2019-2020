//Esame 09.06.16, versione con struct modificata. Marco il massimo con max1 e chiamo max2 e restituisco il massimo stando attento a quando incontro il nodo marchiato.

#include <stdio.h>
#include <stdlib.h>


typedef struct _node {
	int rimosso; //1 se rimosso altrimenti 0
	int key;
	struct _node *left;
	struct _node *right;
} node;


node* insert(node* T, int key) {
	node* temp=T;
	node* prec=NULL;
	node* new=malloc(sizeof(node));
	new->left=NULL;	
	new->right=NULL;
	new->key=key;
	new->rimosso=0;

	if (T==NULL) {
		T=new;
		return T;
	}
	else {

		while (temp!=NULL) {
			prec=temp;
			if (key<temp->key)		
				temp=temp->left;
			else temp=temp->right;
		}
	}
	
	if (key < prec->key)
		prec->left=new;
	else prec->right=new;
	
	return T;
}


void in_visit(node* T) {
	if (T!=NULL) {
		in_visit(T->left);
		printf("%d ", T->key);
		in_visit(T->right);
	}

}


void max1(node* T) {
	node* temp=T;
	node* prec=NULL;

	while (temp!=NULL) {
		prec=temp;
		temp=temp->right;
	}
	prec->rimosso=1;

	return;
}


int max2(node* T) {
	node* temp=T;
	node* prec=NULL;

	while (temp!=NULL) {
		if (temp->rimosso==1) {
			if (temp->right==NULL)
			temp=temp->left;
			else temp=temp->right;
		}
		else {
		prec=temp;
		temp=temp->right;
		}
	}
	
	return prec->key;


}


int main() {
int N, val;
scanf("%d", &N);
node* T=NULL;


for (int i=0;i<N;i++) {
	scanf("%d", &val);
	T=insert(T, val);
}

max1(T);
int valore=max2(T); 
printf("%d", valore);

return 0;
}
