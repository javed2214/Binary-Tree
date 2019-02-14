// Program to Construct Binary Tree From Inorder and Postorder Traversal

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

node *buildTree(vector<int> &in, vector<int> &post, int inS, int inE, int postS, int postE){

	if(inS > inE) return NULL;

	int rootData=post[postE];
	int rootIndex=-1;

	for(int i=inS;i<=inE;i++){
		if(rootData==in[i]){
			rootIndex=i;
			break;
		}
	}
	int lInS=inS;
    int lInE=rootIndex-1;
    int rInS=rootIndex+1;
    int rInE=inE;
    int lPostS=postS;
    int lPostE=lPostS+lInE-lInS;	// lInE-lInS=lPostE-lPostS
    int rPostS=lPostE+1;
    int rPostE=postE-1;

	node *root=createNode(rootData);
	root->left=buildTree(in,post,lInS,lInE,lPostS,lPostE);
	root->right=buildTree(in,post,rInS,rInE,rPostS,rPostE);

	return root;
}

node *helperFunc(vector<int> &in, vector<int> &post){
	return buildTree(in,post,0,in.size()-1,0,post.size()-1);
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int main(){

	vector<int> in,post;
	in={9,3,15,20,7};
	post={9,15,7,20,3};

	node *root=NULL;
	root=helperFunc(in,post);

	cout<<"Inorder: ";
	inOrder(root);

	return 0;
}