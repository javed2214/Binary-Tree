// Program to Check Whether All Leaf Nodes are at Same Level or Not
// https://www.geeksforgeeks.org/check-leaves-level/
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

bool checkLeafLevels(node *root, int *leafLevel, int level){

	if(root == NULL) return true;

	if(root->left == NULL and root->right == NULL){

		if(*leafLevel == 0){
			*leafLevel = level;
			return true;
		}
		return (*leafLevel == level);
	}
	return checkLeafLevels(root->left, leafLevel, level + 1) and checkLeafLevels(root->right, leafLevel, level + 1);
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	int leafLevel = 0;
	int level = 0;

	int x = checkLeafLevels(root, &leafLevel, level);

	if(x) cout<<"Yes";
	else cout<<"No";

	return 0;
}