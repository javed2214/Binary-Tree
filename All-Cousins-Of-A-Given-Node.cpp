// Proram to Print All the Cousins of a Given Node in a Binary Tree
// geeksforgeeks.org/print-cousins-of-a-given-node-in-binary-tree-single-traversal/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void printCousins(node *root, node *k){

	if(root == k){
		cout<<"No Cousin Nodes!";
		return;
	}

	queue <node *> q;
	q.push(root);

	int siz = -1, found = false;

	while(!q.empty()){

		siz = q.size();

		for(int i=0;i<siz;i++){

			node *temp = q.front();
			q.pop();

			if(temp->left == k or temp->right == k) found = true;
			
			else{
				if(temp->left) q.push(temp->left);
				if(temp->right) q.push(temp->right);
			}
		}
		
		if(found) break;
	}

	if(found){

		if(siz == 0){
			cout<<"No Cousin Nodes!";
			return;
		}

		for(int i=0;i<siz;i++){
			
			node *x = q.front();
			q.pop();
			cout<<x->data<<" ";
		}
	}
	return;
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	root->right->right->right = createNode(8);

	printCousins(root, root->right->left);

	return 0;
}