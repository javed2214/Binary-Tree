// Deletion of NODE from Binary Search Tree.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inorderDisplay(node *);
node *NodeDeletion(node *, int);
node *minNode(node *);

int main()
{
	int n,choice,x;
	node *root=NULL;
	
	while(1)
	{
		printf("\n1. Create Node\n");
		printf("2. Inorder Traversal\n");
		printf("3. Delete Node\n");
		printf("4. Exit\n");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Node Data: ");
				scanf("%d",&n);
				root=createNode(root, n);
				break;

			case 2:
				printf("\n");
				inorderDisplay(root);
				printf("\n");
				break;

			case 3:
				printf("\nEnter Node Data to Delete: ");
				scanf("%d",&x);
				root=NodeDeletion(root, x);
				break;

			case 4:
				exit(0);
		}
	}
	return 0;
}
node *createNode(node *root, int n)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
	}
	else if(n < root->data)
		root->left=createNode(root->left, n);
	else if(n > root->data)
		root->right=createNode(root->right, n);
	else if(n==root->data)
		printf("Duplicate Node");

	return root;
}
void inorderDisplay(node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorderDisplay(root->left);
		printf("%d ",root->data);
		inorderDisplay(root->right);
	}
}
node *NodeDeletion(node *root, int x)
{
	if(root==NULL)
		return NULL;
	else if(x<root->data)
		root->left=NodeDeletion(root->left, x);
	else if(x>root->data)
		root->right=NodeDeletion(root->right, x);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{								// No Children
			free(root);
			root=NULL;
		}
		else if(root->left==NULL)					// Right Child
		{
			node *temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL)					// Left Child
		{
			node *temp=root;
			root=root->left;
			free(temp);
		}
		else								// Two Children
		{
			node *temp=minNode(root->right);
			root->data=temp->data;
			root->right=NodeDeletion(root->right, temp->data);
		}
	}

	return root;
}
node *minNode(node *root)
{
	if(root==NULL)
		return NULL;
	minNode(root->left);
	return root;
}
