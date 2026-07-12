//Wap to demonstrate global and local structures

#include<stdio.h>

struct emp_details{
    char *name;
    int age;
    int salary;
}emp1,emp2;

int manager(){                //function without argument
    struct manager_details{
        char *name;
        int age;
        int salary;
    };

    struct manager_details m1;
    m1.age=26;
    if (m1.age>30){
        m1.salary=90000;
    }
    else{
        m1.salary=75000;
    }
    return m1.salary;

}
int main(){
    printf("enter the salary of emp1:");
    scanf("%d",&emp1.salary);
    printf("enter the salary of emp1:");
    scanf("%d",&emp2.salary);
    printf("salary of emp1 and emp2 is %d & %d\n",emp1.salary,emp2.salary);
    printf("salary of manager is %d\n",manager());
    return 0;
}
