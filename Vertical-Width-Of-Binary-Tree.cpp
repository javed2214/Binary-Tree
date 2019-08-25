// Program to Find Vertical Width of Binary Tree
// https://www.geeksforgeeks.org/vertical-width-binary-tree-set-2/

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

unordered_set <int> S;

void verticalWidth(node *root, int hd = 0){

	if(root){

		S.insert(hd);
		verticalWidth(root->left, hd - 1);
		verticalWidth(root->right, hd + 1);
	}
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	verticalWidth(root);

	cout << S.size();

	return 0;
}