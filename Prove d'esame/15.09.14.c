#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int key;
	struct nodo* left;
	struct nodo* right;
	int L;	
	int R;

};


struct el {
	int L;
	int R;
};


struct nodo* insert (struct nodo* testa, int val) {
	//creo nodo
	struct nodo* new= malloc (sizeof(struct nodo));
	new->key=val;
	new->left=NULL;
	new->right=NULL;

		//inserisco nodo
	//albero vuoto
	if (testa==NULL) {
		testa=new;
		return testa;	
	}
	//altrimenti
	struct nodo* parent;
	struct nodo* current= testa;
	while (current!=NULL) {
		parent=current;
		if (current->key < val)
			current=current->right;
		else current=current->left;
	}

	if (parent->key < val) parent->right=new;
	else parent->left=new;

	return testa;
}


struct el algo(struct nodo* u) {
	struct el temp, s1, s2;
	
	if (u==NULL) {
		temp.L=0;
		temp.R=0;
		return temp;
	}
	
	if (u->left==NULL && u->right==NULL) {
		temp.L=0;
		temp.R=0;
		return temp;
	}

	s1=algo(u->left);
	s2=algo(u->right);
	int L=s1.L;
	int R=s2.R;
	
	if (u->left!=NULL)
		L=L+1;
	if (u->right!=NULL)	
		R=R+1;
	u->L=L;
	u->R=R;
	temp.L=L;
	temp.R=R;

	return temp;	
}

/*
void print(struct nodo* testa) {
	if (testa!=NULL) {
		print(testa->left);
		printf("[%d ", testa->key);
		printf("L:%d ", testa->L);
		printf("R:%d]", testa->R);
		print(testa->right);
	}

}
*/

void printmod (struct nodo* testa) {
	if (testa!=NULL) {
		printmod(testa->left);

		if ( (testa->L) > (testa->R) ) {
			printf("%d \n", testa->key);
		}

		printmod(testa->right);
	}
}


int main() {
	
int N, valore;
scanf("%d", &N);

struct nodo* head=NULL;

for (int i=0;i<N;i++) {
	scanf("%d", &valore);
	head=insert(head, valore);	
}

algo(head);
printmod (head);


return 0;
}
