//swap using call by reference
#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int var1=10,var2=20;
    printf("before swap: var1=%d , var2=%d\n",var1,var2);
    swap(&var1,&var2);
    printf("after swap: var1=%d , var2=%d\n",var1,var2);
    return 0;
}