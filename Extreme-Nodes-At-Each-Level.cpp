// Program to Print Extreme Nodes at Each Level of Binary Tree in Alternate Level
// https://www.geeksforgeeks.org/print-extreme-nodes-of-each-level-of-binary-tree-in-alternate-order/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void extremeNodes(node *root){

	queue <node *> q;
	q.push(root);
	int level=0;

	while(!q.empty()){
		int s=q.size();
		for(int i=0;i<s;i++){
			node *temp=q.front();
			q.pop();
			if(level%2==0 and i==s-1) cout<<temp->data<<" ";
			else if(level%2!=0 and i==0) cout<<temp->data<<" ";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		level+=1;
	}
	return;
}

int main(){

	node *root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->right->right->right->right  = newNode(31);

    extremeNodes(root);

    return 0;
}