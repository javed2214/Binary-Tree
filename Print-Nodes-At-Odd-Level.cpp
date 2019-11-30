// Print Nodes At Odd Level
// 

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

// ======================== METHOD 1 ==============================

void bfs(node *root){

	queue <node *> q;
	q.push(root);

	int cnt = 1;

	while(!q.empty()){

		int siz = q.size();
		
		vector <int> v;

		for(int i=0;i<siz;i++){

			node *temp = q.front();
			q.pop();

			if(cnt & 1) v.push_back(temp->data);

			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		for(auto it:v) cout<<it<<" ";

		cnt++;
	}
}

// ======================== METHOD 2 ==============================

void dfs(node *root, int odd){

	if(root == NULL) return;

	if(odd) cout<<root->data<<" ";

	dfs(root->left, !odd);
	dfs(root->right, !odd);
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

	cout<<endl<<endl;

	dfs(root, true);

	return 0;
}