// Burn the Binary Tree Starting from Target Node
// https://www.geeksforgeeks.org/burn-the-binary-tree-starting-from-the-target-node/
// Application of "All Nodes at K Distance in a Binary Tree".
// https://github.com/javed2214/Binary-Tree/blob/master/All-Nodes-At-K-Distance.cpp

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

unordered_map <node *, node *> parent;
unordered_map <node *, int> vis;

void dfs(node *root){

	if(root){

		vis[root] = 1;

		if(root->left and vis[root->left] == 0){
			parent[root->left] = root;
			dfs(root->left);
		}
		if(root->right and vis[root->right] == 0){
			parent[root->right] = root;
			dfs(root->right);
		}
	}
}

void bfs(node *root){

	queue <node *> q;
	q.push(root);

	vis.clear();

	vis[root] = 1;

	int flag = 0;

	while(!q.empty()){

		int siz = q.size();

		for(int i=0;i<siz;i++){

			node *temp = q.front();
			q.pop();

			if(temp) flag = 1, cout<<temp->data<<" ";

			if(temp and temp->left and vis[temp->left] == 0) vis[temp->left] = 1, q.push(temp->left);
			if(temp and temp->right and vis[temp->right] == 0) vis[temp->right] = 1, q.push(temp->right);
			if(temp and vis[parent[temp]] == 0) vis[parent[temp]] = 1, q.push(parent[temp]);

		}

		if(flag == 1) cout<<"\n";

		flag = 0;
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

	dfs(root);

	node *target = root->left;

	bfs(target);

	return 0;
}