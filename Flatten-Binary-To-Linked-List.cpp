// Program to Flatten Binary Tree to a Singly Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;

}node;

vector <int> v1,v2;

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

node *pre = NULL;

void flatten(node *root){

	if(!root) return;

	flatten(root->right);
	flatten(root->left);
	
	root->left = NULL;
	root->right = pre;
	pre = root;
}

void printList(node *head){

	while(head){
		cout<<head->data<<"->";
		head = head->right;
	}
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(5);
	root->left->left = createNode(3);
	root->left->right = createNode(4);
	root->right->right = createNode(6);

	flatten(root);

	printList(root);

	return 0;
}