#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createTree(node *root, int n){
	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;

		return root;
	}
	else if(n<root->data)
		root->left=createTree(root->left,n);
	else if(n>root->data)
		root->right=createTree(root->right,n);
}

int levelOrder(node *root){

	if(root==NULL) return 0;

	vector<int> v;
	queue<node *>q;	
	q.push(root);
	int sum=0;
	while(!q.empty()){
		int s=q.size();
		sum=0;
		for(int i=0;i<s;i++){
			node *temp=q.front();
			q.pop();
			sum+=(temp->data);
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		v.push_back(sum);
	}
	
	int p=*max_element(v.begin(),v.end());

	return p;
}

int main(){

	node *root=NULL;
	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	
	cout<<levelOrder(root);

	return 0;
}