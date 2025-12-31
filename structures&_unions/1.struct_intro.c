/* structure is a user defined data type that can be used to group elements of different data type
  into a single type  */


//define a structure to store the details of car specification like engine name, fuel_type, fuel_tank_cap, seating_cap, and mileage
#include<stdio.h>

struct spec{
    char *engine;
    char *fule_type;
    int fule_tank_cap;
    int seating_cap;
    float mileage;
} car1,car2;

int main(){
    // struct spec car1;
    // struct spec car2;
    car1.engine="DDIS 190 ENGINE";
    car2.engine="1.2 L Kappa Dual VTVT";
    printf("car1 engine= %s\n",car1.engine);
    printf("car2 engine= %s\n",car2.engine);
    return 0;
}