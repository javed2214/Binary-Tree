// Program to find Postorder Predecessor of a Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void postOrder(node *root, vector<int> &v){

	if(root){
		postOrder(root->left,v);
		postOrder(root->right,v);
		v.push_back(root->data);
	}
}

int main(){

	node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

    int k;
    cin>>k;

    vector<int> v;
    postOrder(root,v);

    for(int i=0;i<v.size();i++){
    	if(v[i]==k and i==0){
    		cout<<v[i];
    		return 0;
    	}
    	if(v[i]==k) cout<<v[i-1];
    }

    return 0;
}