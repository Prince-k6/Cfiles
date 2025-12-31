/*  structure within a structure (also called nested structure) 
    refers to defining a structure within a structure                     */
//This allows you to create more complex data structures by emeddding one structure within another

#include<stdio.h>
struct Address{      
    char *street;
    char *city;
    int zip;
};

struct person{       //outer structure
    char *name;
    int age;
    struct Address address;    //nested structure
};

int main(){
    struct person p1={"John Doe", 30, {"123 Main St", "New York", 10001}};
    //Accessing nested structure members
    printf("Name:%s\n",p1.name);
    printf("Age:%d\n",p1.age);
    printf("Street:%s\n",p1.address.street);
    printf("City:%s\n",p1.address.city);
    printf("ZIP code:%d\n",p1.address.zip);
    return 0;
}

