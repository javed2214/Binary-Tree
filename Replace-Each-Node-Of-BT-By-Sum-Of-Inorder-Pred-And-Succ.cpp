// Replace Each Node of Binary Tree by Inorder Predecessor and Successor
// https://www.geeksforgeeks.org/replace-node-binary-tree-sum-inorder-predecessor-successor/

#include<bits/stdc++.h>
using namespace std;

vector <int> v;
int index = 1;

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

void storeInorder(node *root){

	if(root){

		storeInorder(root->left);
		v.push_back(root->data);
		storeInorder(root->right);
	}
}

void replaceNodes(node *root){

	if(root){

		replaceNodes(root->left);
		root->data = v[index - 1] + v[index + 1];
		index++;
		replaceNodes(root->right);
	}
}

void inorderTraversal(node *root){

	if(root){

		inorderTraversal(root->left);
		cout << root->data << " ";
		inorderTraversal(root->right);
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

	inorderTraversal(root);

	v.push_back(0);
	storeInorder(root);
	v.push_back(0);

	replaceNodes(root);

	cout << endl;

	inorderTraversal(root);

	return 0;
}