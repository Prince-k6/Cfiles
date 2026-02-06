
//double ended queque : queue in which insertion and deletion can happend from both side
/*
operations
    1.insert_at_front()
    2.delete_at_front()
    3.insert_at_rear()
    4.delete_at_rear()
    5.display()
    6.is_empty()
    7.is_full()

*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int deque[MAX];
int f=-1;
int r=-1;
/*
empty condition : front==-1
full condition : front==(rear+1)%size
one element condition : frontt==rear


*/
int isempty(){
    if(f==-1){
        return 1;
    }return 0;
}
int isfull(){
    if(f==(r+1)%MAX){
        return 1;
    }return 0;
}

void insert_atfront(int val){
    if(f==(r+1)%MAX){
        printf("deque overflow\n");
        return;
    }else if(f==-1){
        f=r=0;
    }else{
        if(f==0){
            f=MAX-1;
        }else{
            f--;
        }
    }
    deque[f]=val;
}

void delete_atfront(){
    int val;
    if(f==-1){
        printf("deque underflow\n");
        return;
    }
    val=deque[f];
    if(f==r){
        f=r=-1;
    }else{
        if(f==MAX-1){
            f=0;
        }else{
            f++;
        }
    }
    printf("%d deleted\n",val);
}

void insert_atrear(int val){
    if(f==(r+1)%MAX){
        printf("Queue oveflow\n");
        return;
    }else if(f==-1){
        r=f=0;
    }else{
        if(r==MAX-1){
            r=0;
        }else{
            r++;
        }
    }
    deque[r]=val;
}

void delete_atrear(){
    int val;
    if(f==-1){
        printf("deque undeflow\n");
        return ;
    }
    val=deque[r];
    if(f==r){
        f=r=-1;
    }else{
        if(r==0){
            r=MAX-1;
        }else{
            r--;
        }
    }
    printf("%d deleted\n",val);
}
void display(){
    if(isempty()){
        printf("Queue is empty\n");
        return;
    }else{
        for(int i=f;i!=r;i=(i+1)%MAX){
            printf("%d\t",deque[i]);
        }
        printf("%d\n",deque[r]);

    }
}
int main(){
    insert_atfront(9);
    insert_atfront(8);
    insert_atfront(7);
    display();
    insert_atrear(4);
    insert_atrear(3);
    display();

    delete_atfront();
    delete_atfront();
    display();
    delete_atrear();
    delete_atrear();
    display();
    delete_atrear();
    display();

    
    return 0;
}

