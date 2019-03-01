// Program to Check if Levels of Two Trees are Anagram or Not

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

bool checkAnagrams(node *root1, node *root2){

	if(root1==NULL and root2==NULL) return true;

	if(root1==NULL or root2==NULL) return false;

	queue <node *> q1,q2;

	q1.push(root1);
	q2.push(root2);

	while(1){

		int n1=q1.size();
		int n2=q2.size();

		if(n1!=n2) return false;
		
		if(n1==0) break;	// Empty Queue Condition
		
		vector <int> v1,v2;

		for(int i=0;i<n1;i++){

			node *temp1=q1.front();
			q1.pop();
			v1.push_back(temp1->data);
			if(temp1->left)
				q1.push(temp1->left);
			if(temp1->right)
				q1.push(temp1->right);

			node *temp2=q2.front();
			q2.pop();
			v2.push_back(temp2->data);
			if(temp2->left)
				q2.push(temp2->left);
			if(temp2->right)
				q2.push(temp2->right);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());

		if(v1!=v2) return false;
	}
	return true;
}

node *newNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int main(){

        node *root1, *root2;
	
	root1=newNode(1);
        root1->left=newNode(3); 
	root1->right=newNode(2); 
	root1->right->left=newNode(5); 
	root1->right->right=newNode(4);

	root2=newNode(1);
	root2->left=newNode(2); 
	root2->right=newNode(3); 
	root2->left->left=newNode(4); 
	root2->left->right=newNode(5);

	if(checkAnagrams(root1, root2)) cout<<"Trees are Anagrams!\n";
	else cout<<"They Aren't!\n";

	return 0;
}
