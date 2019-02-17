// Diagonal Traversal of Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createTree(node *root, int n){

	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;

		return root;
	}
	else if(n < root->data)
		root->left=createTree(root->left,n);
	else if(n > root->data)
		root->right=createTree(root->right,n);
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void diagonalTraversal(node *root, int d, map<int,vector<int>> &Map){

	if(root==NULL) return;
	Map[d].push_back(root->data);
	diagonalTraversal(root->left,d+1,Map);
	diagonalTraversal(root->right,d,Map);
}

int main(){

	int a[]={20,10,30,5,15,25,35};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	inOrder(root);

	cout<<"\nDiagonal Traversal: \n";
	map<int,vector<int>> Map;
	diagonalTraversal(root,0,Map);

	for(auto it:Map){
		for(auto ptr:it.second)
			cout<<ptr<<" ";
		cout<<"\n";
	}


	return 0;

}