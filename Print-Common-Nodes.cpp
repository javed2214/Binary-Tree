// Program to Print Common Nodes of Two Binary Trees

#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq1,pq2;

void pushNodes(node *root, priority_queue<int> &pq){
	
	if(root){
		pq.push(root->data);
		pushNodes(root->left,pq);
		pushNodes(root->right,pq);
	}
}

void commonNodes(node *root1, node *root2){

	if(root1==NULL or root2==NULL) return;
	pushNodes(root1,pq1);
	pushNodes(root2,pq2);
}	
				
int main(){

	int a[]={20,10,30,5,15,25,35};
	int n1=sizeof(a)/sizeof(int);

	int b[]={30,17,46,15,35};
	int n2=sizeof(b)/sizeof(int);

	cout<<"Common Nodes: ";
	commonNodes(root1,root2);

	int flag=0;	
	while(!pq1.empty() and !pq2.empty()){

		if(pq1.top() > pq2.top()) pq1.pop();
		else if(pq1.top() < pq2.top()) pq2.pop();
		else{
			cout<<pq1.top()<<" ";
			pq1.pop();
			pq2.pop();
			flag=1;
		}
	}
	if(flag==0) cout<<"None!";

	return 0;
}