// Program to Find Level of a Node Iteratively

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *getnode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int nodeLevel(node *root, int k){

	queue<node *> q;
	q.push(root);
	int level=1;

	while(!q.empty()){
		int s=q.size();
		for(int i=0;i<s;i++){
			node *temp=q.front();
			if(temp->data==k) return level;
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		level++;
	}
	return -1;
}

int main(){

	node* root = getnode(20); 
    root->left = getnode(10); 
    root->right = getnode(30); 
    root->left->left = getnode(5); 
    root->left->right = getnode(15); 
    root->left->right->left = getnode(12); 
    root->right->left = getnode(25); 
    root->right->right = getnode(40); 

    int x=nodeLevel(root,40);
	
	if(x==-1) cout<<"Node Not Found!";
	else cout<<"Level: "<<x;

	return 0;
}