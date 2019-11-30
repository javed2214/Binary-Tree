// Print Nodes Between Two Given Levels
// https://www.geeksforgeeks.org/given-binary-tree-print-nodes-two-given-level-numbers/

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

void bfs(node *root, int l, int r){

	queue <node *> q;
	q.push(root);

	int cnt = 1, flag = 0;

	while(!q.empty()){

		int siz = q.size();
		flag = 0;

		for(int i=0;i<siz;i++){

			node *temp = q.front();
			q.pop();

			if(cnt >= l and cnt <= r){

				flag = 1;
				cout<<temp->data<<" ";
			}

			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}

		cnt += 1;

		if(flag) cout<<endl;
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

	int l, r;
	cin>>l>>r;

	bfs(root, l, r);

	return 0;
}