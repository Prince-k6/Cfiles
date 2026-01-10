//implementing hash table
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct{
    int key;
    char name[20];
} Emp;

Emp *hashtable[100];        //hashtble using arrays
#define tablesize 5            //or take user input

//hash function : it returns the hash value on taking key
int hash_fun(int k){
    return k%tablesize;
}
//function to display hash table contents
void displayHashtable(){
    printf("-------hash table contents------\n");
    for(int i=0;i<tablesize;i++){
        printf("Index=%d:  ",i);
        if(hashtable[i]==NULL){
            printf("Empty\n");
        }else{
            printf("key:%d, Name:%s\n",hashtable[i]->key,hashtable[i]->name);
        }
    }
    printf("-----------------------\n");
}

//insetion in hashtable with linear probing
void linear_probing_insert(int key, char name[]){
    Emp *newdata=(Emp *)malloc(sizeof(Emp));
    if(newdata==NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
    newdata->key=key;
    strcpy(newdata->name,name);
    int index=hash_fun(key);   //store the hash value in index

    while(hashtable[index]!=NULL){
        printf("collision occured at index %d with key %d, probing...\n",index,hashtable[index]->key);
        index=(index+1)%tablesize;   //linear probing 
        //check for infinite loop
        if(index==hash_fun(key)){
            printf("hash table full cannot insert key %d\n",key);
            return;
        }
    }
    hashtable[index]=newdata;
}
//function to search for a record with given key value
void search(int srchkey){
    int original_index=hash_fun(srchkey);
    int index=original_index;

    while(hashtable[index]!=NULL){
        if(hashtable[index]->key==srchkey){
            printf("record with key %d was found\n",srchkey);
            break;
        }
        index=(index+1)%tablesize;
        if(index==original_index){
            printf("record with key %d was not found\n",srchkey);
            break;
        }
    }
}

int main(){

    //initialise hash table to NULL
    for(int i=0;i<tablesize;i++){
        hashtable[i]=NULL;
    }
    displayHashtable();

    linear_probing_insert(445,"prince");
    linear_probing_insert(267,"lemon");
    linear_probing_insert(87,"apple");
    linear_probing_insert(41,"atq");
    linear_probing_insert(23,"dffd");
    
    displayHashtable();
    search(445);
    search(8);

    return 0;

}