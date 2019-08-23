// Program to Check If there is a Root to Leaf Path with Givaen Sequence
// https://www.geeksforgeeks.org/check-root-leaf-path-given-sequence/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;

	node(int x){

		data = x;
		left = NULL;
		right = NULL;
	}
}node;

bool exist(node *root, int *a, int n, int index){

	if(root == NULL) return n == 0;
	if(!root->left and !root->right and root->data == a[index] and index == (n - 1)) return true;
	return ((index < n) and root->data == a[index] and ((exist(root->left,a,n,index + 1)) or (exist(root->right,a,n,index + 1))));
}

int main(){

	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left ->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	int a[] = {1,2,4};
	int n = sizeof(a)/sizeof(int);

	bool x = exist(root,a,n,0);

	if(x) cout<<"Yes";
	else cout<<"No";

	return 0;
}