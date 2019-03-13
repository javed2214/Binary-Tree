// Program to Find Deepest Right Leaf Node in a Binary Tree Iteratively
// https://www.geeksforgeeks.org/deepest-right-leaf-node-binary-tree-iterative-approach/

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

int deepestRightLeaf(node *root){

	queue <node *> q;
	q.push(root);
	int res;

	while(!q.empty()){

		node *temp=q.front();
		q.pop();
		if(temp->left) q.push(temp->left);
		if(temp->right){
			q.push(temp->right);
			if(!temp->right->left and !temp->right->right)
				res=temp->right->data;
		}
	}
	return res;
}

int main(){

	node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->right = newNode(8); 
    root->right->left->right->left = newNode(9); 
    root->right->right->right->right = newNode(10); 	

   	cout<<deepestRightLeaf(root);

    return 0;
}