// Anticlockwise Spiral Traversal of Binary Tree
// https://www.geeksforgeeks.org/anti-clockwise-spiral-traversal-of-a-binary-tree/

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

void printVector(vector<vector<int>> &res){

	int start=0;
	int end=res.size()-1;
	int count=0;

	while(start<=end){
		if(count%2==0){
			reverse(res[start].begin(),res[start].end());
			for(int i=0;i<res[start].size();i++)
				cout<<res[start][i]<<" ";
			start++;
		}
		else{
			for(int i=0;i<res[end].size();i++)
				cout<<res[end][i]<<" ";
			end--;
		}
		count++;
	}
}

void antiClockwiseSpiral(node *root){

	queue<node *> Q;
	Q.push(root);
	vector<vector<int>> res;

	while(!Q.empty()){
		int s=Q.size();
		vector<int> v;
		for(int i=0;i<s;i++){
			node *temp=Q.front();
			Q.pop();
			v.push_back(temp->data);
			if(temp->left)  Q.push(temp->left);
			if(temp->right) Q.push(temp->right);
 		}
 		res.push_back(v);
	}
	printVector(res);
}

int main(){

	node *root = newNode(1);
	root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(10); 
    root->left->left->right = newNode(11); 
    root->right->right->left = newNode(8); 

    antiClockwiseSpiral(root);

    return 0;
}