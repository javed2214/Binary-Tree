// Inorder, Preorder and Postorder Traversal in TREE Data Structure.

#include<stdio.h>
#include<conio.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inorder(node *);
void preorder(node *);
void postorder(node *);

void main()
{
	int choice, n;
	node *root=NULL;

	clrscr();

	while(1)
	{
		printf("\n1. Enter 1 for Insertion");
		printf("\n2. Inorder Traversal");
		printf("\n3. Preorder Traversal");
		printf("\n4. Postorder Traversal");
		printf("\n5. Exit\n");

		printf("\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Data to Insert: ");
				scanf("%d",&n);
				root=createNode(root, n);
				break;

			case 2:
				printf("\n");
				inorder(root);
				break;

			case 3:
				printf("\n");
				preorder(root);
				break;

			case 4:
				printf("\n");
				postorder(root);
				break;

			case 5:
				exit(1);
		}
	}
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
	else if(n <= root->data)
	{
		root->left=createNode(root->left, n);
	}
	else
	{
		root->right=createNode(root->right, n);
	}
	return root;
}
void inorder(node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root==NULL)
		return;

	else
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}	
