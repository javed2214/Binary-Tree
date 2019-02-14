// Program to Construct Binary Tree From Inorder and Preorder Traversals
// https://www.youtube.com/watch?v=W9irlUOf6lI

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){
	
	node *root=(node *)malloc(sizeof(node));
	root->data=x;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

node *buildTree(int *in, int *pre, int inS, int inE, int preS, int preE){
	
	if(inS > inE) return NULL;

	int rootData=pre[preS];
	int rootIndex=-1;
	for(int i=inS;i<=inE;i++){
		if(in[i]==rootData){
			rootIndex=i;
			break;
		}
	}
	int lInS,lInE,rInS,rInE,lPreS,lPreE,rPreS,rPreE;
	lInS=inS;
	lInE=rootIndex-1;
	rInS=rootIndex+1;
	rInE=inE;
	lPreS=preS+1;
	lPreE=lInE-lInS+lPreS;		// lInS-lInE=lPreS-lPreE ==>> lPreE=lInE-lInS+lPreS
	rPreS=lPreE+1;
	rPreE=preE;
	node *root=createNode(rootData);
	root->left=buildTree(in,pre,lInS,lInE,lPreS,lPreE);
	root->right=buildTree(in,pre,rInS,rInE,rPreS,rPreE);

	return root;
}

node *buildTreeUtil(int *in, int *pre, int siz){
	node *root=buildTree(in,pre,0,siz-1,0,siz-1);
}

int main(){

	int in[]={4,2,5,1,8,6,9,3,7};
	int pre[]={1,2,4,5,3,6,8,9,7};
	int siz=sizeof(in)/sizeof(int);

	node *root=NULL;
	root=buildTreeUtil(in,pre,siz);

	inOrder(root);

	return 0;
}
