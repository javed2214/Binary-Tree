// Program to Print All the Diagonal Sums of a Binary Tree
// https://www.geeksforgeeks.org/diagonal-sum-binary-tree/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){

	node *root=new node;
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void diagonalSum(node *root, int d, map<int,vector<int>> &Map){

	if(root==NULL) return;
	Map[d].push_back(root->data);
	diagonalSum(root->left,d+1,Map);
	diagonalSum(root->right,d,Map);
}

int main(){

	node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 

    map<int,vector<int>> Map;
    diagonalSum(root,0,Map);

    int sum=0;
    for(auto it:Map){
    	sum=0;
    	for(auto ptr:it.second)
    		sum+=ptr;
    	cout<<sum<<" ";
    }
    return 0;
}