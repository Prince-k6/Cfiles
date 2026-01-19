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
                              //global root pointer 

//creating a node
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
struct node *insert(struct node *root, int val){
    if(root==NULL){
        return createNode(val);
    }else if(root->data==val){
        return root;
    }else if(val>root->data){
        root->right=insert(root->right,val);
    }else{//(val<root->data){
        root->left=insert(root->left,val);
    }
    return root;
}

//creating a bst with an array of integers
struct node *create_bst(struct node *root, int arr[], int n){
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

/*=================================================Traversal==================================================*/
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

void search(struct node *root,int key){
    if(root==NULL){
        printf("element %d not found\n",key);
    }else if(root->data==key){
        printf("element %d found\n",key);
    }else if(key>root->data){
        search(root->right,key);
    }else{
        search(root->left,key);
    }
}

int main(){
    struct node *root=NULL;
    int arr[]={6,9,5,2,8,15,24,14,7,8,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    // printf("size=%d\n",n);
    // root=create_bst(root,arr,n);

    // printf("inorder\n");
    // inorder(root);
    // printf("\npreorder\n");
    // preorder(root);
    // printf("\npostorder\n");
    // postorder(root);
    // printf("\n");


    // search(root,9);

    // search(root,8);
    // search(root,13);
    int choice,key;
    printf("1.create bst\n");
    printf("2.traversal\n");
    printf("3.search\n");
    printf("4.exit\n");
    while(choice!=4){
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                root=create_bst(root,arr,n);
                break;
            case 2:
                printf("inorder\n");
                inorder(root);
                printf("\npreorder\n");
                preorder(root);
                printf("\npostorder\n");
                postorder(root);
                printf("\n");
                break;
            case 3:
                printf("enter element to search:");
                scanf("%d",&key);
                search(root,key);
                break;
            case 4:
                printf("Exiting program....\n");
                exit(0);
            default:
                printf("invalid choice\n");
                break;
        }
    }
    return 0;
}