#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int queue[MAX];
int f=-1;
int r=-1;

//full condtion : rear==Size-1
//empty contion : front ==-1;
//one element condition : front==rear

int isempty(){
    if(f==-1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(r==MAX-1){
        return 1;
    }
    return 0;
}
void enqueue(int val){
    if(isfull()){
        printf("queue overflow\n");
        return;
    }
    else if(f==-1){
        f=0;
        r=0;
    }else{
        r++;
    }
    queue[r]=val;
}
void dequeue(){
    int val;
    if(isempty()){
        printf("undeflow\n");
        return;
    }else if(f==r){
        val=queue[f];
        f=r=-1;
    }else{
        val=queue[f];
        f++;
    }
    printf("%d deleted\n",val);
}
void display(){
    if(isempty()){
        printf("queue is empty\n");
        return ;
    }else{
        for(int i=f;i<=r;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    enqueue(9);
    enqueue(9);
    enqueue(9);
    enqueue(9);
    enqueue(9);
    enqueue(10);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    dequeue();

    // int choice,data;
    // printf("1\n");
    // printf("2\n");
    // printf("3\n");
    // printf("4\n");
    // while(choice!=4){
    //     printf("enter choice:");
    //     scanf("%d",&choice);
    //     switch (choice){
    //         case 1:
    //             enqueue(data);
    //             break;
    //         case 2:
    //             dequeue();
    //             break;
    //         case 3:
    //             display();
    //             break;
    //         case 4:
    //             exit(0);
    //             break;
    //         default:
    //             break;
    //     }
    // }
    return 0;
}