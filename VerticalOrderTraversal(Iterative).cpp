// Program to Find Vertical Order Traversal of a Binary Tree
// Using Queue (Ierative Approach)

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
	else if(n<root->data)
		root->left=createTree(root->left, n);
	else if(n>root->data)
		root->right=createTree(root->right, n);
}

void printTree(node *root){
	if(root){
		printTree(root->left);
		cout<<root->data<<" ";
		printTree(root->right);
	}
}

void printverticalOrder(node *root){
	
	if(root==NULL) return;
		
	int hd=0;
	queue<pair<node*,int>>q;
	q.push(make_pair(root,hd));
	map<int,vector<int>>Map;
	
	while(!q.empty()){
		pair<node*,int>temp=q.front();
		hd=temp.second;
		node *p=temp.first;
		q.pop();
		Map[hd].push_back(p->data);
		if(p->left!=NULL)
			q.push(make_pair(p->left,hd-1));
		if(p->right!=NULL)
			q.push(make_pair(p->right,hd+1));	
	}
	for(auto it:Map){
		for(auto ptr:it.second)
			cout<<ptr<<" ";
		cout<<"\n";
	}
}

int main(){	
	int a[]={20,10,40,5,2,7,15,12,18,30,22,35,50,45,60};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	printTree(root);
	cout<<"\n\nVertical Order: \n";
	printverticalOrder(root);

	return 0;
}
