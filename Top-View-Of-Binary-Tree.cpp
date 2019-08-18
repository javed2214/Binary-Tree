// Program to Print Top view of Binary Tree
// https://www.youtube.com/watch?v=c3SAvcjWb1E

#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> Map;
unordered_map<int,int> M;

int co = 0;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){

	node *root = (node *)malloc(sizeof(node));
	root->data = x;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void verticalOrder(node *root, int hd){

	if(root == NULL) return;
	Map[hd].push_back(root->data);
	verticalOrder(root->left, hd - 1);
	verticalOrder(root->right, hd + 1);
}

void bfs(node *root){

	queue <node *> q;
	q.push(root);

	while(!q.empty()){

		node *temp = q.front();
		q.pop();

		M[temp->data] = co++;

		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
}

int getNode(vector<int> &v){

	int mx = INT_MAX;
	int x = -1;

	for(int i=0;i<v.size();i++){
		if(M[v[i]] < mx){
			x = v[i];
			mx = M[v[i]];
		}
	}
	return x;
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	verticalOrder(root, 0);
	bfs(root);

	vector <int> v;

	for(auto it:Map){
		for(auto pt:it.second){
			v.push_back(pt);
		}
		cout<<getNode(v)<<" ";
		v.clear();
	}

	return 0;
}