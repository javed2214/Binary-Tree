/* Root to Leaf Tree Sum
		1
	  /   \	  => 12 + 13 = 25
	 2     3
*/

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

int getSum(node *root, int sum){

	if(root==NULL) return 0;
	sum=sum*10+root->data;
	if(root->left==NULL and root->right==NULL) return sum;
	return getSum(root->left,sum) + getSum(root->right,sum);
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);

	cout<<getSum(root,0);

	return 0;
}