#include<stdio.h>

struct spec{
    int fuel_tank_cap;
    int seating_cap;
    float city_mileage;
};
int main (){
    struct spec car[2];
    int i;
    for (i=0; i<2; i++){
        printf("Enter the car %d fuel tank capacity: ",i+1);
        scanf("%d",&car[i]. fuel_tank_cap);
        printf("Enter the car %d seating capacity: ", i+1);
        scanf("%d",&car[i].seating_cap);
        printf("Enter the car %d city mileage: ", i+1) ;
        scanf("%f",&car[i].city_mileage) ;
        printf("\n") ;
    }
    for (i=0; i<2; i++){
        printf("\nCar %d details: \n", i+1);
        printf("fuel tank capacity: %d\n", car[i].fuel_tank_cap);
        printf("seating capacity: %d\n", car[i].seating_cap) ;
        printf("city mileage: %f\n", car[i].city_mileage) ;
    }
    return 0;
}

//create an array of n students to store their (roll no,name,marks,and grade) 

struct student{
    int roll_no;
    char *name;
    float marks;
    char grade;
};

int main(){
    int n;
    printf("enter the no.of students:");
    scanf("%d",&n);
    struct student s[n];

    for(int i=0;i<n;i++){
        printf("enter roll no:");
        scanf("%d",&s[i].roll_no);

        printf("enter name:");
        fgets(s[i].name,100,stdin);

        printf("enter marks:");
        acanf("%f",&s[i].marks);

        printf("enter grade:");
        scanf("%c",&s[i].grade);
        
    }
    for(int i=0;i<n;i++){
        printf("enter roll no:%d",s[i].roll_no);
        printf("enter name:%s",s[i].name);
        printf("enter marks:%f",s[i].marks);
        printf("enter grade:%c",s[i].grade);
        
    }
    return 0;

}