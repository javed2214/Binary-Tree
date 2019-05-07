// Right View of Binary Tree

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

// Method-I
void rightView1(node *root, vector<int> &v, int level){

	if(root==NULL) return;
	if(v.size()==level) v.push_back(root->data);
	rightView1(root->right,v,level+1);
	rightView1(root->left,v,level+1);
} 

// Method-II
void rightView2(node *root, int *p, int level){

	if(root==NULL) return;
	if(*p==level) cout<<root->data<<" ", (*p)++;
	rightView2(root->right,p,level+1);
	rightView2(root->left,p,level+1);
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);
	root->right->right->right=createNode(8);

	vector<int> v;
	rightView1(root,v,0);
	for(auto it:v) cout<<it<<" ";
	
	cout<<"\n";
	
	int p=0;
	rightView2(root,&p,0);

	return 0;	
}