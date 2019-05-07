// Left View of Binary Tree

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

// Method-1
void leftView1(node *root, vector<int> &v, int level){

	if(root==NULL) return;
	if(v.size()==level) v.push_back(root->data);
	leftView1(root->left,v,level+1);
	leftView1(root->right,v,level+1);
}

// Method-2
void leftView2(node *root, int *p, int level){

	if(root==NULL) return;
	if(*p==level) cout<<root->data<<" ", (*p)++;
	leftView2(root->left,p,level+1);
	leftView2(root->right,p,level+1);
}

int main(){

	node *root=createNode(4);
	root->left=createNode(5);
	root->right=createNode(2);
	root->right->left=createNode(3);
	root->right->right=createNode(1);
	root->right->left->left=createNode(6);
	root->right->left->right=createNode(7);

	vector<int> v;
	leftView1(root,v,0);
	for(auto it:v) cout<<it<<" ";

	cout<<"\n";
	
	int p=0;
	leftView2(root,&p,0);

	return 0;
}