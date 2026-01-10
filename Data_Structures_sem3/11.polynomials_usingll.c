// polynomials using linked list

/*
operations:-
    1.create & insert
    2.display
    3.add
    4.subtract
    5.multiply
    6.Evaluate (value at x=um)
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    float coeff;
    int expo;
    struct node *next;
};
struct node *insert(struct node *head, float co, int ex);    //declaration    
/*===========================================CREATION=======================================================*/
struct node *create(struct node *head){
    int n;
    printf("enter the number of terms: ");
    scanf("%d",&n);
    float coeff;
    int expo;
    for(int i=0;i<n;i++){
        printf("enter the coeff. of term %d: ",i+1);
        scanf("%f",&coeff);
        printf("enter the exponent of term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
/*===========================================INSERTATION=====================================================*/
//This function inserts the terms of polynomial according to there exponent  | sorted linked list
struct node *insert(struct node *head, float co, int ex){        
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->coeff=co;
    new->expo=ex;
    new->next=NULL;
    //for deciding where the new->next should point
    if(head==NULL || ex > head->expo){         //then insert at begining 
        new->next=head;          
        head=new;
    }
    else{                                      //else insert at end
        struct node *temp=head;
        while(temp->next!=NULL && ex <= temp->next->expo){
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return head;
}
/*===========================================DISPLAY=========================================================*/
void display(struct node *head){
    if(head==NULL){
        printf("linked list is empty\n");
        return ;
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("(%.1fx^%d)",ptr->coeff,ptr->expo);
        ptr=ptr->next;
        if(ptr!=NULL){
            printf("+");
        }else{
            printf("\n");
        }

    }
}
/*===========================================ADDITION========================================================*/
void add(struct node *head1, struct node *head2){
    // struct node *result=(struct node *)malloc(sizeof(struct node));
    struct node *result=NULL;
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->expo>temp2->expo){
            result=insert(result,temp1->coeff,temp1->expo);
            temp1=temp1->next;
        }else if(temp1->expo<temp2->expo){
            result=insert(result,temp2->coeff,temp2->expo);
            temp2=temp2->next;
        }else{         //power is equal
            result=insert(result,temp1->coeff+temp2->coeff,temp1->expo);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        result=insert(result,temp1->coeff,temp1->expo);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        result=insert(result,temp2->coeff,temp2->expo);
        temp2=temp2->next;
    }
    printf("----------------Addition of polynomials:---------------------------------\n");
    display(result);
    // return result;
}
/*===========================================SUBTRACTION=====================================================*/
void sub(struct node *head1, struct node *head2){
    // struct node *result=(struct node *)malloc(sizeof(struct node));
    struct node *result=NULL;
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL && temp2!=NULL){

        if(temp1->expo>temp2->expo){
            result=insert(result,temp1->coeff,temp1->expo);
            temp1=temp1->next;
        }else if(temp1->expo<temp2->expo){
            result=insert(result,-temp2->coeff,temp2->expo);
            temp2=temp2->next;
        }else{         //power is equal
            result=insert(result,temp1->coeff-temp2->coeff,temp1->expo);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        result=insert(result,temp1->coeff,temp1->expo);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        result=insert(result,-temp2->coeff,temp2->expo);
        temp2=temp2->next;
    }
    printf("----------------subtraction of polynomials:------------------------------\n");
    display(result);
    // return result;
}
/*===========================================MULTIPLICATION==================================================*/
void multiply(struct node *head1,struct node *head2){
    struct node *result=NULL;
    if(head1==NULL || head2==NULL){
        printf("zero polynomial\n");
        return;
    }
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL){              //each term of temp1 will be multiplied by the each term of temp2
        while(temp2!=NULL){
            result=insert(result,temp1->coeff*temp2->coeff,temp1->expo+temp2->expo);
            temp2=temp2->next;
        }
        temp2=head2;              //for pointing to head node of polynomial2 once again
        temp1=temp1->next;
    }
    //for adding like terms (i.e terms with same degree)
    struct node *temp3=result;
    while(temp3->next!=NULL){
        if(temp3->expo==temp3->next->expo){
            temp3->coeff+=temp3->next->coeff;
            struct node *ptr=temp3->next;
            temp3->next=ptr->next;
            free(ptr); ptr=NULL;
        }else{
            temp3=temp3->next;
        }
    }
    printf("----------------multiplication of polynomials:---------------------------\n");
    display(result);

}
/*===========================================EVALUATE========================================================*/
//evaulate:-value of the polynomial at x=num
void evaluate(struct node *head){
    float num;
    printf("enter the value at which you wanna evaluate "); display(head);
    printf("x= ");
    scanf("%f",&num);
    float sum=0;
    struct node *ptr=head;
    while(ptr!=NULL){
        sum+=ptr->coeff*pow(num,ptr->expo);
        ptr=ptr->next;
    }
    display(head);printf("at x=%.2f is : %.2f\n",num,sum);

}
/*===========================================================================================================*/
struct node *createNode(float coeff,int exp){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->expo=exp;
    newNode->next=NULL;
    return newNode;
}
int main(){
    // struct node *head1=NULL;
    // struct node *head2=NULL;
    // printf("enter polynomial 1\n");
    // head1=create(head1);
    // printf("--------------------------------------\n");
    // printf("enter polynomial 2\n");
    // head2=create(head2);
    // printf("--------------------------------------\n");

    // printf("---------polynomial1------------------\n");
    // display(head1);
    // printf("---------polynomial2------------------\n");
    // display(head2);

    struct node *head1=createNode(4,3);        //polynomial 1
    struct node *t2=createNode(3,2);
    struct node *t3=createNode(1,0);
    head1->next=t2;t2->next=t3;t3->next=NULL;
    display(head1);

    struct node *head2=createNode(5,3);        //polynomial 2
    struct node *m2=createNode(7,1);
    struct node *m3=createNode(5,0);
    head2->next=m2;m2->next=m3;m3->next=NULL;
    display(head2);

    add(head1,head2);
    sub(head1,head2);

    multiply(head1,head2);
    printf("=========================================================================\n");
    evaluate(head1);
    evaluate(head2);

    return 0;
}