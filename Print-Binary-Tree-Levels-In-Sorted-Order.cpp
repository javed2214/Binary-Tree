// Print Binary Tree Levels in Sorted Order
// https://www.geeksforgeeks.org/print-binary-tree-levels-sorted-order-2/

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

	set <int> s;

	while(!q.empty()){

		int siz = q.size();
		s.clear();

		for(int i=0;i<siz;i++){

			node *temp = q.front();
			q.pop();

			s.insert(temp->data);

			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		for(auto it:s) cout<<it<<" ";

		cout<<endl;
	}
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(7);
	root->right->left = createNode(6);
	root->right->right = createNode(5);

	bfs(root);
}