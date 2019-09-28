// Spiral Level Order Traversal using Two Stacks
// https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

// Time Complexity: O(n)
// Space Complexity: O(n)

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

void spiralOrderTraversal(node *root){

	if(!root) return;

	stack <node *> s1;
	stack <node *> s2;

	s1.push(root);

	while(!s1.empty() or !s2.empty()){

		while(!s1.empty()){
			node *temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right) s2.push(temp->right);
			if(temp->left) s2.push(temp->left);
		}

		while(!s2.empty()){
			node *temp = s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left) s1.push(temp->left);
			if(temp->right) s1.push(temp->right);
		}
	}
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	spiralOrderTraversal(root);

	return 0;
}