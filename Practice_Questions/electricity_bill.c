//Electricity bill

#include<stdio.h>
//function for solving x% of y
float xpercenty(float x,float y);
float xpercenty(float x,float y){
    return (x*y)/100;
}

int main(){
    char name[20];
    printf("enter name:");
    scanf("%s",name);
    float units,charges;          //charges-->including meter charge
    printf("enter units consumed:");
    scanf("%f",&units);
    charges=0+100;   // 100-->meter charge 
    if (units<=200){
        charges+=(0.8*units);
    }
    else{
        if (units<=300){
            charges+=(0.8*200)+(0.9*(units-200));
        }
        else{
            charges+=(0.8*200)+(0.9*100)+(1*(units-300));
        }
    }
    printf("------------------\n");
    printf("your name:");
    puts(name);
    printf("units consumed:%.2f\n",units);
    if (charges<=400){
        printf("total amt to be paid:%.3f\n",charges);
    }
    else{
        charges+=xpercenty(15,charges);
        printf("total amt to be paid:%.3f\n",charges);    
    }
    printf("-------------------\n");
    return 0;
}