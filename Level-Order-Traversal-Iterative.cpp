// Level Order Traversal of a Binary Tree
// Using Queue (Iterative Approach)

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

vector<vector<int>> levelOrder(node *root){

	queue <node *> q;
	q.push(root);
	vector<vector<int>> res;
	while(!q.empty()){
		int s=q.size();
		vector<int> v;
		for(int i=0;i<s;i++){
			node *temp=q.front();
			v.push_back(temp->data);
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		res.push_back(v);
	}
	return res;
}

/*

void levelOrder(node *root){

	queue <node *> q;
	q.push(root);
	while(!q.empty()){
		node *temp=q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
}

*/


int main(){

	node *root=createNode(10);
	root->left=createNode(30);
	root->right=createNode(7);
	root->right->left=createNode(20);
	root->left->left=createNode(8);
	root->left->right=createNode(4);
	root->left->right->right=createNode(2);
	root->right->left->right=createNode(45);	

	vector<vector<int>> res;
	res=levelOrder(root);

	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}

	return 0;
}

