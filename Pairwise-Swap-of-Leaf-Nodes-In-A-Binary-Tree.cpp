// PairWise Swap of Leaf Nodes in a Binary Tree
// https://www.geeksforgeeks.org/pairwise-swap-leaf-nodes-binary-tree/
// Asked in Most of the Interviews

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void inorder(node *root){

	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void Swap(node **a, node **b){

	node *temp = *a;
	*a = *b;
	*b = temp;
}

node **firstPtr = NULL, **secondPtr = NULL;

void pairwiseSwap(node **root, int &count){

	if(!(*root)) return;

	if(!(*root)->left and !(*root)->right){

		secondPtr = root;
		count++;
		if(count % 2 == 0) Swap(firstPtr, secondPtr);
		else firstPtr = secondPtr;
	}

	if((*root)->left) pairwiseSwap(&(*root)->left, count);
	if((*root)->right) pairwiseSwap(&(*root)->right, count);
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	inorder(root);
	cout<<endl;

	int co = 0;

	pairwiseSwap(&root, co);
	inorder(root);

	return 0;
}