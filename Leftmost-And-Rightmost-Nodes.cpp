// Program to Print Leftmost and Rightmost Nodes of a Binary Tree
// Using Level Order Traversal

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void levelOrder(node *root, vector<vector<int>> &res){

	if(root==NULL) return;

	queue<node *> q;
	q.push(root);

	while(!q.empty()){
		vector<int> v;
		int s=q.size();
		for(int i=0;i<s;i++){
			node *temp=q.front();
			q.pop();
			v.push_back(temp->data);
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		res.push_back(v);
	}
}

int main(){

	node *root=createNode(10);
	root->left=createNode(20);
	root->right=createNode(30);
	root->left->left=createNode(40);
	root->left->right=createNode(50);
	root->right->left=createNode(60);
	root->right->right=createNode(70);

	vector<vector<int>> res;
	levelOrder(root,res);

	for(int i=0;i<res.size();i++){
		if(res[i].size()>=2)
			cout<<res[i][0]<<" "<<res[i][res[i].size()-1]<<" ";
		else cout<<res[i][0]<<" "; 
	}

	return 0;
}