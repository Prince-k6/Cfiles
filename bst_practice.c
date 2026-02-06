//binary search Trees
/*
8. Develop a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers.
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
//createnode
struct node *createNode(int val){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(new==NULL){
        printf("memory allocation failed\n");
        exit(0);
    }
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}
//insertion
struct node *insert(struct node *root,int val){
    if(root==NULL){
        return createNode(val);
    }else{
        if(val==root->data){
            return root;
        }else if(val>root->data){
            root->right=insert(root->right,val);
        }else{
            root->left=insert(root->left,val);
        }
    }
    return root;
}
//creation
struct node *create_bst(struct node *root, int arr[],int n){
    if(root!=NULL){
        printf("BST already exist\n");
    }else{
        for(int i=0;i<n;i++){
            root=insert(root,arr[i]);
        }
        printf("BST created successfully\n");
    }
    return root;
}
//traversal
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
//searching
void search(struct node *root,int key){
    if(root==NULL){
        printf("%d not found\n",key);
    }else if(root->data==key){
        printf("%d found\n",key);
    }else if(key>root->data){
        search(root->right,key);
    }else{
        search(root->left,key);
    }
}
//deletion
struct node *deleteNode(struct node *root,int key){
    if(root==NULL){
        return NULL;
    }else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }else if(key<root->data){
        root->left=deleteNode(root->left,key);
    }else{ //key==root->data
        //1.leaf node condition
        if(root->right==NULL && root->left==NULL){
            free(root);
            root=NULL;
        }
        //2.one node condition
        else if(root->right==NULL){      //left node exist
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL){      //right node exist
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        //3.both node exist
        else{
            //find the inorder predecessor of node to be deleted and replace with it
            struct node *parent=root;
            struct node *child=root->left;
            while(child->right!=NULL){
                parent=child;
                child=child->right;
            }
            if(root!=parent){
                parent->right=child->left;
                child->left=root->left;
                child->right=root->right;
                free(root);
                return child;
            }else{
                child->right=root->right;
                free(root);
                return child;
            }
        }
    }
    return root;
}

int main(){
    int arr[]={6,9,5,2,8,15,24,14,7,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    struct node *root=NULL;
    root=create_bst(root,arr,n);

    // printf("preorder\n");preorder(root); printf("\n");
    printf("inorder\n");inorder(root); printf("\n");
    // printf("postorder\n");postorder(root); printf("\n");

    // search(root,8);
    // search(root,11);
    // search(root,14);

    root=deleteNode(root,9);
    printf("inorder\n");inorder(root); printf("\n");

    return 0;
}

