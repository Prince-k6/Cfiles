#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q){
    return q->f==-1;
}
int isfull(struct queue *q){
    return q->f==(q->r+1)%q->size;
}
// void resize(struct queue *q) {           //didn't understand
//     int oldSize = q->size;
//     int newSize = oldSize * 2;
//     int *newArr = (int *)malloc(newSize * sizeof(int));
//     if (newArr == NULL) {
//         printf("Memory allocation failed\n");
//         return;
//     }
//     int i = q->f;
//     int j = 0;
//     // copy elements in correct FIFO order
//     while (i != q->r) {
//         newArr[j++] = q->arr[i];
//         i = (i + 1) % oldSize;
//     }
//     newArr[j++] = q->arr[q->r];  // copy last element
//     free(q->arr);
//     q->arr = newArr;
//     q->size = newSize;
//     q->f = 0;
//     q->r = j - 1;
// }
void enqueue(struct queue *q,int val){
    if(isfull(q)){
        // printf("queue overflow\n");
        // return;
        resize(q);
    }else if(isempty(q)){
        q->f=q->r=0;
    }else{
        q->r=(q->r+1)%q->size;
    }
    q->arr[q->r]=val;
}
void dequeue(struct queue *q){
    int val;
    if(isempty(q)){
        printf("queue underflow\n");
        return;
    }else if(q->f==q->r){       //one element condition
        val=q->arr[q->f];
        q->f=q->r=-1;
    }else{
        val=q->arr[q->f];
        q->f=(q->f+1)%q->size;
    }
    printf("%d deleted\n",val);
}
void display(struct queue *q){
    if(isempty(q)){
        printf("queue is empty\n");
        return;
    }else{
        for(int i=q->f;i!=q->r;i=(i+1)%q->size){
            printf("%d\t",q->arr[i]);
        }
        printf("%d\n",q->arr[q->r]);  //printing last element
    }
}

int main(){
    int n;
    printf("enter the size of circular queue:");
    scanf("%d",&n);
    struct queue *q;
    q->size=n;
    q->f=q->r=-1;
    q->arr=(int *)malloc(q->size * sizeof(int));

    int choice,element;
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.Exit\n");
    while(choice!=4){
        printf("enter choice:");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("enter element to insert:");
            scanf("%d",&element);
            enqueue(q,element);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            printf("Queue status\n");
            display(q);
            break;
        case 4:
            printf("Exiting program....\n");
            exit(0);
        default:
            printf("invald choice\n");
            break;
        }
    }
    return 0;
}

