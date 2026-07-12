//members of structures can be initialised using dot(.) operator

#include<stdio.h>

struct spec{
    char *engine;
    char *fule_type;
    int fule_tank_cap;
    int seating_cap;
    float mileage;
};

// int main(){
//     struct spec car1={"DDIS 190 Engine","Diesel",37,5,19.74};   //declaring and intialising 
//     struct spec car2={"KAPPA","Petrol",22,8,14.5};

//     printf("Car1 engine=%s\n",car1.engine);    //accessing assined values
//     printf("Car2 mileage=%f\n",car2.mileage);

//     return 0;
// }
                  

                     //desiganted initialisation
//Designated initialization allows structure members to be initialized in any order.
struct abc{
    int x; 
    int y; 
    int z;
};
int main(){
    struct abc a = {.y = 20,.x = 10,.z = 30};
    printf("%d %d %d\n", a.x, a.y, a.z); //output 10 20 30
    return 0;
}
