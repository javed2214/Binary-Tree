// Difference between Sums of Odd Level and Even Level Nodes of a Binary Tree
// https://www.geeksforgeeks.org/difference-between-sums-of-odd-and-even-levels/

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

int rootHeight(node *root){

	if(root==NULL) return 0;
	return 1+max(rootHeight(root->left), rootHeight(root->right));
}

void getLevelSumDiff(node *root, int level, int &odd, int &even, int x){

	if(root==NULL) return;
	if(level==0){
		if(x%2==0) even+=root->data;
		else odd+=root->data;
	}
	getLevelSumDiff(root->left,level-1,odd,even,x);
	getLevelSumDiff(root->right,level-1,odd,even,x);
}

int utilFunction(node *root){

	int h=rootHeight(root);
	int odd=0,even=0,x=1;
	for(int i=0;i<h;i++)
		getLevelSumDiff(root,i,odd,even,x++);

	return (odd-even);
}

/*
int iterativeMethod(node *root){

	queue <node *> q;
	q.push(root);
	int level=1;
	int odd=0,even=0;

	while(!q.empty()){
		int s=q.size();
		for(int i=0;i<s;i++){
			node *temp=q.front();
			q.pop();
			if(level%2==0) even+=temp->data;
			else odd+=temp->data;
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		level+=1;
	}
	return (odd-even);
}
*/

int main(){

	node *root = newNode(5); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(4); 
    root->left->right->left = newNode(3); 
    root->right->right = newNode(8); 
    root->right->right->right = newNode(9); 
    root->right->right->left = newNode(7);

    cout<<utilFunction(root);
    // cout<<iterativeMethod(root);

    return 0;
}