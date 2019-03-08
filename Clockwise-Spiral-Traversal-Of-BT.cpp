// Clockwise Spiral Traversal of Binary Tree
// https://www.geeksforgeeks.org/clockwise-spiral-traversal-of-binary-tree/

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
			for(int i=0;i<res[start].size();i++)
				cout<<res[start][i]<<" ";
			start++;
		}
		else{
			reverse(res[end].begin(),res[end].end());
			for(int i=0;i<res[end].size();i++)
				cout<<res[end][i]<<" ";
			end--;
		}
		count++;
	}
}

void clockwiseSpiral(node *root){

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

	node *root = newNode(10);
	root->left = newNode(12); 
    root->right = newNode(13); 
  
    root->right->left = newNode(14); 
    root->right->right = newNode(15); 
  
    root->right->left->left = newNode(21); 
    root->right->left->right = newNode(22); 
    root->right->right->left = newNode(23); 
    root->right->right->right = newNode(24); 

    clockwiseSpiral(root);

    return 0;
}