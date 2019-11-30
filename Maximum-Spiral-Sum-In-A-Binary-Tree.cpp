// Program to Find Maximum Spiral Sum in a Binary Tree
// https://www.geeksforgeeks.org/maximum-spiral-sum-in-binary-tree/

// Algorithm :-
// 1. First Store Spiral Order Traversal in a Vector
// 2. Run Kadane's Algorithm to Find Max Sum Subarray

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;

}node;

node *newNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


int kadanesAlgo(vector <int> &v){

	int n = v.size();
	int sum = 0, mx = 0;

	for(int i=0;i<n;i++){

		sum += v[i];
		mx = max(mx, sum);
		if(sum < 0) sum = 0;
	}
	return mx;
}

vector <vector<int>> res;

int getMaxSum(node *root){

	stack <node *> s1, s2;
	vector <int> v;

	s1.push(root);

	while(!s1.empty() or !s2.empty()){

		while(!s1.empty()){

			node *temp = s1.top();
			s1.pop();

			v.push_back(temp->data);

			if(temp->right) s2.push(temp->right);
			if(temp->left) s2.push(temp->left);
		}

		while(!s2.empty()){

			node *temp = s2.top();
			s2.pop();

			v.push_back(temp->data);

			if(temp->left) s1.push(temp->left);
			if(temp->right) s1.push(temp->right);
		}
	}

	return kadanesAlgo(v);
}

int main(){

	node* root = newNode(-2); 
    root->left = newNode(-3); 
    root->right = newNode(4); 
    root->left->left = newNode(5); 
    root->left->right = newNode(1); 
    root->right->left = newNode(-2); 
    root->right->right = newNode(-1); 
    root->left->left->left = newNode(-3); 
    root->right->right->right = newNode(2);

    cout << getMaxSum(root);

    return 0;
}
