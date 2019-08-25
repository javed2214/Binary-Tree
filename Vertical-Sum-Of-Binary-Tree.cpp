// Program to Find the Vertical Sum of Binary Tree
// https://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/
// Application of "Vertical Order Traversal".

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

void verticalSum(node *root, int hd){

	if(root){

		Map[hd].push_back(root->data);
		verticalSum(root->left, hd - 1);
		verticalSum(root->right, hd + 1);
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

	verticalSum(root, 0);

	int sum = 0;

	for(auto it:Map){
		sum = 0;
		for(auto pt:it.second){
			sum += pt;
		}
		cout<<sum<<endl;
	}

	return 0;
}
