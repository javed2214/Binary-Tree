// Max Sum From Root to Leaf of a Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

static int s=INT_MIN;
void getSum(std::vector<int> &v){

	int p=accumulate(v.begin(),v.end(),0);   // Calculate Vector Sum
	s=max(s,p);
}

void maxSum(node *root, std::vector<int> v){

	if(root==NULL) return;
	v.push_back(root->data);
	if(root->left==NULL and root->right==NULL)
		getSum(v);
	maxSum(root->left,v);
	maxSum(root->right,v);
}

int main(){

	node *root=createNode(10);
	root->left=createNode(30);
	root->right=createNode(7);
	root->left->left=createNode(-8);
	root->left->right=createNode(-4);
	root->left->right->right=createNode(-2);

	std::vector<int> v;

	maxSum(root,v);

	cout<<s;

	return 0;
}

