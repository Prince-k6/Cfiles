//creating a binary tree
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}


int main(){
    struct node *p=createNode(4);
    struct node *p1=createNode(1);
    struct node *p2=createNode(6);
    struct node *p3=createNode(5);
    struct node *p4=createNode(2);
    //p5-->Null
    struct node *p6=createNode(8);

    /*
                                    4
                                  /   \
                                 1     6
                               /  \   /  \
                              5    2 N    8
    */

    // linking the root node with p1 & p2 node
    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    p2->right=p6;

    printf("preorder: ");preorder(p); printf("\n");
    printf("inorder: "); inorder(p); printf("\n");
    printf("postorder: ");postorder(p); printf("\n");
    return 0;
}