// Construct binary Tree from Given Parent Array Representation
// https://www.techiedelight.com/build-binary-tree-given-parent-array/

// * Asked in Amazon *

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;

}node;

node *newNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

node *createTree(int *parent, int n){

	unordered_map <int,node *> Map;

	for(int i=0;i<n;i++) Map[i] = newNode(i);

	node *root = NULL;
	
	for(int i=0;i<n;i++){

		if(parent[i] == -1) root = Map[i];
		else{
			node *ptr = Map[parent[i]];
			if(ptr->left) ptr->right = Map[i];
			else ptr->left = Map[i];
		}
	}

	return root;
}

void inorder(node *root){

	if(root){

		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

int main(){

	int parent[] = {-1,0,0,1,2,2,4,4};
	int n = sizeof(parent) / sizeof(int);

	node *root = createTree(parent, n);

	inorder(root);

	return 0;
}