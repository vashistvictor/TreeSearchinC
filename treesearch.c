#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create(int value)
{
    struct node *root;
    root = (struct node*)malloc(sizeof(struct node));
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node * search1(struct node *root, int item)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == item)
    {
        return root;
    }
    else if(root->data > item)
    {
        return search1(root->left,item);
    }
    else
    {
        return search1(root->right,item);
    }
}

struct node * search2(struct node *root, int item)
{
    while(root!=NULL)
    {
    if(root->data == item)
    {
        return root;
    }
    else if(root->data > item)
    {
        root = root->left;
    }
    else
    {
        root = root->right;
    }
    }
    return NULL;
}

int main()
{
    struct node *p = create(12);
    struct node *p1 = create(7);
    struct node *p2 = create(21);
    struct node *p3 = create(3);
    struct node *p4 = create(10);
    struct node *p5 = create(26);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    inorder(p);
    struct node *k1 = search1(p,10);
    if(k1==NULL)
        printf("\nnot found");
    else
        printf("\n %d found",k1->data);
    struct node *k2 = search2(p,10);
    if(k2==NULL)
        printf("\nnot present");
    else
        printf("\n %d present",k2->data);
    return 0;
}
