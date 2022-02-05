#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right,*left;
};
struct node *create()
{
    struct node *newnode;
    int x;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data(if there is no child please enter 0):\n");
    scanf("%d",&x);
    if(x==0)
    {
        return 0;
    }
    newnode->data=x;
    printf("\nEnter the left child of %d\n",x);
    newnode->left=create();
    printf("\nEnter the right child of %d\n",x);
    newnode->right=create();
    return newnode;
}
void inorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);

}
void preorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);

}
void postorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);

}
void main()
{
    struct node *root;
    root=create();
    printf("\nInorder traversing:\t");
    inorder(root);
    printf("\nPreorder traversing:\t");
    preorder(root);
    printf("\nPostorder traversing:\t");
    postorder(root);

}
