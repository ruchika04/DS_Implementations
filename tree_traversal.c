#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
     int data;
     struct node* left;
     struct node* right;
} node;
//creating new node
/*node* newNode(int data)
{
     node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}*/
node *create()
{
	node *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);

	if(x==-1)
		return NULL;

	p=(node*)malloc(sizeof(node));
	p->data=x;

	printf("Enter left child of %d:\n",x);
	p->left=create();

	printf("Enter right child of %d:\n",x);
	p->right=create();

	return p;
}
void printPostorder(
                    node* node)
{
     if (node == NULL)
        return;
     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data);
}
void printInorder(node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}
void printPreorder(node* node)
{
     if (node == NULL)
          return;
     printf("%d ", node->data);
     printPreorder(node->left);
     printPreorder(node->right);
}
int main()
{
	node *root;
	root=create();
	printf("\nThe postorder traversal of tree is:\n");
	printPostorder(root);
    printf("\nThe inorder traversal of tree is:\n");
	printInorder(root);
	printf("\nThe preorder traversal of tree is:\n");
	printPreorder(root);
	return 0;
}
