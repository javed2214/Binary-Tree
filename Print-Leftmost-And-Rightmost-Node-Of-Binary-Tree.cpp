// Print Leftmost and Rightmost Node of Binary Tree
// https://www.geeksforgeeks.org/print-leftmost-and-rightmost-nodes-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct node{

	int data;
	struct node *left;
	struct node *right;
};

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void bfs(node *root){

	queue <node *> q;
	q.push(root);

	vector <int> v;

	while(!q.empty()){

		int siz = q.size();

		for(int i=0;i<siz;i++){

			node *temp = q.front();
			q.pop();

			if(i == 0) v.push_back(temp->data);
			else if(i == siz - 1) v.push_back(temp->data);

			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}

	for(auto it:v) cout<<it<<" ";

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

	bfs(root);
}