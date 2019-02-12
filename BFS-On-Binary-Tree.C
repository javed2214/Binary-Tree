// Breadth First Search (BFS) of a Binary Tree (Level Order Traversal).

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 100

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int, node *);
void bfs(node *);
void enqueue(node *);
node *dequeue();
int queueEmpty();

node *queue[size];
int front=-1;
int rear=-1;

void main()
{
	int n,choice;
	node *root=NULL;

	clrscr();

	while(1)
	{
		printf("\n1. Create Node");
		printf("\n2. Breadth First Search of BT");
		printf("\n3. Exit\n");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter Data to Insert: ");
				scanf("%d",&n);
				root=createNode(n,root);
				break;

			case 2:
				printf("\n");
				bfs(root);
				printf("\n");
				break;

			case 3:
				exit(1);
		}
	}
}
node *createNode(int n, node *root)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
	}
	else if(n < root->data)
		root->left=createNode(n, root->left);
	else if(n > root->data)
		root->right=createNode(n, root->right);
	else
		printf("\nDuplicate Node\n");

	return root;
}
void bfs(node *root)
{
	node *p=root;

	if(root==NULL)
		printf("\nTree is Empty\n");
	else
	{
		enqueue(p);
		while(queueEmpty())
		{
			p=dequeue();
			printf("| %d |\t",p->data);
			if(p->left!=NULL)
				enqueue(p->left);
			if(p->right!=NULL)
				enqueue(p->right);
		}
	}
}
void enqueue(node *root)
{
	if(rear==size-1 )
	{
		printf("\nQueue Overflow!\n");
		delay(1000);
		exit(1);
	}
	if(rear==-1 && front==-1)
		rear=front=0;
	else
		rear++;
	queue[rear]=root;
}
node *dequeue()
{
	node *p=NULL;
	if(front==-1 || front > rear)
	{
		printf("\nQueue Underflow\n");
		return NULL;
	}
	else
	{
		p=queue[front];
		front++;
		if(front > rear)
			front=rear=-1;
		return p;
	}
}
int queueEmpty()
{
	if(front==-1 && rear==-1)
		return 0;
	else
		return 1;
}
