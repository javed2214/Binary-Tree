// Program to Print Bottom View of Binary Tree
// https://www.geeksforgeeks.org/bottom-view-binary-tree/

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
		root->left=createTree(root->left,n);
	else if(n>root->data)
		root->right=createTree(root->right,n);
}

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void bottomView(node *root, int height, int hd, map<int,pair<int,int>>&Map){

	if(root==NULL) return;

	if(Map.find(hd)==Map.end()){
		Map[hd]=make_pair(root->data,height);
	}
	else{
		pair<int,int> p=Map[hd];
		if(p.second <= height){
			Map[hd].first=root->data;
			Map[hd].second=height;
		}
	}
	bottomView(root->left,height+1,hd-1,Map);
	bottomView(root->right,height+1,hd+1,Map);
}

void printBottomView(node *root){

	map<int,pair<int,int>>Map;
	bottomView(root,0,0,Map);

	for(auto it:Map){
		cout<<it.second.first<<" ";
	}
}

int main(){

	int a[]={20,10,40,5,15,30,50};
	int n=sizeof(a)/sizeof(int);
	node *root=NULL;
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	
	cout<<"Inorder: ";
	inOrder(root);

	cout<<"\nVertical Order: ";
	printBottomView(root);

	return 0;
}