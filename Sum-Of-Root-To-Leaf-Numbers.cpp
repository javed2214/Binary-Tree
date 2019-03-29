// Program to Find Sum of all the Numbers Formed from Root to Leaves of a BT
// // https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

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

int res=0;
void calSum(vector<int> &v){

	int sum=0;
	for(int i=0;i<v.size();i++)
		sum=(sum*10)+v[i];
	cout<<sum<<" ";
	res+=sum;
}

void getNumbers(node *root, vector<int> v){

	if(root==NULL) return;
	v.push_back(root->data);
	if(root->left==NULL and root->right==NULL) calSum(v);
	getNumbers(root->left,v);
	getNumbers(root->right,v);
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);

	vector<int> v;
	getNumbers(root,v);

	cout<<res;

	return 0;
}