// Program to Find Max Width of binary Tree
// https://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/

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

int maxWidth(node *root){

	queue <node *> q;
	q.push(root);

	int mx = -1;

	while(!q.empty()){

		int siz = q.size();
		
		mx = max(mx, siz);

		for(int i=0;i<siz;i++){

			node *temp = q.front();
			q.pop();

			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return mx;
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	cout << maxWidth(root);

	return 0;
}