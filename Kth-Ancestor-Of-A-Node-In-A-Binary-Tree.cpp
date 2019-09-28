// Program to Find Kth Ancestor of any Node in a Binary Tree

#include<bits/stdc++.h>
using namespace std;
#define MX 1001

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

bool KthAncestor(node *root, int nod, int &k){

	if(root == NULL) return false;

	if(nod == root->data) return true;

	if(KthAncestor(root->left, nod, k) or KthAncestor(root->right, nod, k)){
		if(k > 0) k--;
		else if(k == 0) cout<<root->data<<" ";

		return true;
	}
	else return false;
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	int nod, k;
	
	cout<<"Enter Node and K Value: ";
	cin>>nod>>k;

	k -= 1;

	KthAncestor(root, nod, k);

	return 0;
}