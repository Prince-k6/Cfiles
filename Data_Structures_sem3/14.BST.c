//Binary search trees

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
                                  //Traversal
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

//insertion
struct node *insert(struct node *root, int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data==root->data){
        return root;
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }else{
        root->left=insert(root->left,data);
    }
    return root;
} 
//creation of BST : construction of binary search tree
struct node *create_bst(struct node *root, int arr[],int n){
    if(root!=NULL){
        printf("BST already exist\n");
    }
    else{
        for(int i=0;i<n;i++){
            root=insert(root,arr[i]);
        }
        printf("BST created successfully\n");
    }
    return root;
}

//searching in BST
void search(struct node *root,int key){
    if(root==NULL){
        printf("element %d not found\n",key);
    }else if(root->data==key){
        printf("element %d found\n",key);
    }else if(key<root->data){
        search(root->left,key);
    }else{
        search(root->right,key);
    }
}
//iterative search
struct node *iterative_search(struct node *root,int key){
    while(root!=NULL){
        if(root->data==key){
            return root;
        }else if(key<root->data){
            // return iterative_search(root->left,key);
            root=root->left;
        }else{
            root=root->right;
        }
    }
    return NULL;
}

                        //deletion in binary tree
struct node *deleteNode(struct node *root,int val){
    if(root==NULL){
        return NULL;}
    //searching the node that has to be deleted
    else if(val<root->data){
        root->left=deleteNode(root->left,val);}
    else if(val>root->data){
        root->right=deleteNode(root->right,val);}
    else{   //root->data=val
        //1.leaf node
        if(root->left==NULL && root->right==NULL){     
            free(root);
            root=NULL;
        }
        //2.one node exist
        else if(root->right==NULL){        //left node exist
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL){          //right node exist
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        //3.both nodes exist
        else{
            //find the greatest element from the left subtree
            struct node *parent=root;
            struct node *child=root->left;
            while(child->right!=NULL){      //reaching to the right most node
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
    struct node *root=NULL;   //root node
    // int arr[]={5,3,6,2,4,8,1};        //creating a bst using an array of elements
    int arr[]={6,9,5,2,8,15,24,14,7,8,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    root=create_bst(root,arr,n);
    
    /*
                                    5
                                  /   \
                                 3     6
                               /  \   /  \
                              1    4 N    8
    */
    printf("inorder \n");  inorder(root);   //ascending order 
    printf("\n");

    //searching
    int key=6;
    search(root,key);
    //iteraive search
    // struct node *s=iterative_search(p,key);
    // if(s!=NULL){
    //     printf("element %d found\n",key);
    // }else{
    //     printf("element %d not found\n",key);
    // }

    //insertion
    insert(root,7);
    inorder(root);   //ascending order 
    printf("\n");

    insert(root,9);
    inorder(root);
    printf("\n");

    //deletion
    // deleteNode(root,6);
    // inorder(root);
    // printf("\n");

    return 0;
}