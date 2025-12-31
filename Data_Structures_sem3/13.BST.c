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
//check if binary tree is BST or not?
int isBST(struct node *root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
//searching in BST
void search(struct node *root,int key){
    if(root==NULL){
        printf("element %d not found\n",key);
    }else if(root->data==key){
        printf("element %d found\n",key);
    }else if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
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
//insertion
void insert(struct node *root, int val){
    struct node *prev=NULL;
    while(root!=NULL){
        prev=root;
        if(val==root->data){
            printf("cannot insert duplicate element\n");
            return;
        }else if(val<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    struct node *newNode=createNode(val);
    if(val<prev->data){
        prev->left=newNode;
    }else{
        prev->right=newNode;
    }
}
//inorder predecessor function : return the inorder preceeding node of a given node
struct node *inorder_predecessor(struct node *root){      //here root node will be a given node
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

//deletion
struct node *deleteNode(struct node *root, int value){
    struct node *ipre;      //ipre = stores inorder predecessor
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){           //leaf node condition
        free(root);
        return NULL;
    }
    //search for the node to delete
    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    //deletion strategy when node is found
    else{
        ipre=inorder_predecessor(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);
    }
    return root;
}



int main(){
    struct node *p=createNode(5);         //root node
    struct node *p1=createNode(3);
    struct node *p2=createNode(6);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);
    struct node *p5=createNode(8);

    /*
                                    5
                                  /   \
                                 3     6
                               /  \   /  \
                              1    4 N    8
    */

    // linking the root node with p1 & p2 node
    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    p2->right=p5;

    //traversal
    // printf("preorder \n"); preorder(p); printf("\n");
    // printf("postorder \n"); postorder(p); printf("\n");

    printf("inorder \n");  inorder(p);   //ascending order 
    printf("\n");

    //searching
    int key=6;
    search(p,key);
    //iteraive search
    // struct node *s=iterative_search(p,key);
    // if(s!=NULL){
    //     printf("element %d found\n",key);
    // }else{
    //     printf("element %d not found\n",key);
    // }

    //insertion
    insert(p,7);
    printf("inorder \n");  inorder(p);   //ascending order 
    printf("\n");

    //deletion
    struct node *newroot=deleteNode(p,8);
    printf("%d\n",newroot->data);
    printf("inorder \n");  inorder(p);   //ascending order 
    printf("\n");


    return 0;
}