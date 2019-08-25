// Program to Print Kth Node in Vertical Order Traversal
// https://www.geeksforgeeks.org/find-the-kth-node-in-vertical-order-traversal-of-a-binary-tree/

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

map <int,vector<int>> Map;

void KthNode(node *root, int hd){

	if(root){

		Map[hd].push_back(root->data);
		KthNode(root->left, hd - 1);
		KthNode(root->right, hd + 1);
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

	int k = 6;

	KthNode(root,0);

	int s = 0;

	for(auto it:Map){
		for(auto pt:it.second){
			s++;
			if(s == k){
				cout<<pt<<" ";
				return 0;
			}
		}
	}
	cout<<"-1";

	return 0;
}