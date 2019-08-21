// Mirror Image HackerEarth
// https://www.hackerearth.com/problem/algorithm/mirror-image-1/

#include<bits/stdc++.h>
using namespace std;
#define MX 1001

typedef struct node{

	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
	
	node(int x){

		left = NULL;
		right = NULL;
		data = x;
		parent = NULL;
	}
}node;


int getImage(node *root, node *x){

	stack <char> S;

	while(x->parent != NULL){

		if(x->parent->left == x) S.push('L');
		else S.push('R');

		x = x->parent;
	}

	node *temp = root;

	while(!S.empty()){

		if(temp == NULL) break;
		if(S.top() == 'L') temp = temp->right;
		else temp = temp->left;

		S.pop();
	}

	if(temp == NULL) return -1;
	return temp->data;
}


int main(){

	int n,q;
	cin>>n>>q;

	node *a[n+1];

	for(int i=0;i<=n;i++) a[i] = new node(i);

	for(int i=0;i<n-1;i++){

		int u,v;
		char ch;
		cin>>u>>v>>ch;

		if(ch == 'L') a[u]->left = a[v];
		else a[u]->right = a[v];

		a[v]->parent = a[u];
	}

	node *root = a[1];

	while(q--){

		int u;
		cin>>u;

		cout<<getImage(root,a[u])<<"\n";
	}

	return 0;
}