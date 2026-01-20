//hash table 
/*
10. Given a set of N employee records with a set K of Keys (4-digit) which
uniquely determine the records. Assume that the records are available in the
memory by a Hash Table (HT) of m memory locations with L as the set of
memory addresses (2-digit) of locations in HT. Let the keys in K and
addresses in L are Integers. Develop a Program in C that uses Hash function
H: K →L as H (K) = K mod m (remainder method), and implement hashing
technique to map a given key K to the address space L. Resolve the collision
(if any) using linear probing.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int key;
    char name[20];
}Employee;

int size;   //hash table size 
Employee *HT[100];      //Hsh table(HT)
//hash funtion
int hashFun(int key){
    return key%size;
}
//insertion using linear probing
void insert(Employee *emp){      
    int index=hashFun(emp->key);
    while(HT[index]!=NULL){
        printf("collision occured at index %d with key %d, probing...\n",index,emp->key);
        index=(index+1)%size;   //circular incrementation
        if(index==hashFun(emp->key)){
            printf("hash table is full\n");
            break;
        }
    }
    HT[index]=emp;
}
//function to display hash table
void display(){
    printf("----Displaying Hash Table----\n");
    for(int i=0;i<size;i++){
        printf("index%d:       ",i);
        if(HT[i]==NULL){
            printf("Empty\n");
        }else{
            printf("%d,%s\n",HT[i]->key,HT[i]->name);
        }
    }
}
//function to search for a given key
void search(int searchkey){
    int original_index=hashFun(searchkey);
    int index=original_index;
    while(HT[index]!=NULL){
        if(HT[index]->key==searchkey){
            printf("Record (%d,%s) found at index %d\n",searchkey,HT[index]->name,index);
            break;
        }
        index=(index+1)%size;
        if(index==original_index){
            printf("Record not found\n");
            break;
        }
    }
}
int main(){
    printf("enter the size of hashtable:");
    scanf("%d",&size);
    for(int i=0;i<size;i++){     //initialise hashtable with null
        HT[i]=NULL;
    }

    int n;
    printf("enter the number of employess:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        Employee *new=(Employee *)malloc(sizeof(Employee));
        if(new==NULL){
            printf("memory allocation failed\n");
            exit(0);
        }
        printf("enter record %d (key Name)\n",i+1);
        scanf("%d %s",&new->key,new->name);
        insert(new);   //insertion using linear probing
    }
    display();

    int searchkey;
    printf("enter key to search:");
    scanf("%d",&searchkey);
    search(searchkey);
    return 0;
}