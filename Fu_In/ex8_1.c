#include <stdio.h>

void select_base_wine_message(){
    printf("Let's select the base wine!\n");
    printf("Please Enter flavor level of the base wine: ");
}

int select_the_base_wine(int *flavor_level,int base_flavor_level){
    flavor_level += base_flavor_level;
    printf("The flavor level level is %d!",*flavor_level);
}

void add_two_wines_message(){
    printf("Now add two kinds of wines.\n");
    printf("Please Enter two types representing each wine: ");
}

int add_two_wines(int *flavor_level,int wine_1,int wine_2){
    int greatest_common_factor=0;
    //find greatest_common_factor
    flavor_level += greatest_common_factor;
    printf("The flavor level increased %d!\n",*flavor_level);    
}

void add_juice_message(){
    printf("Now add some juice.\n");
    printf("Please Enter flavor level of the juice: ");
}

int add_juice(int *flavor_level,int juice_flavor_level){
    flavor_level += juice_flavor_level;
    printf("The flavor level increased %d!\n",*flavor_level);
}

void add_co2_mesage(int flavor_level){
    printf("Now add some CO2.\n");
    printf("The current flavor level is %d.\n",flavor_level);
    printf("Please Enter power of CO2: ");
}

int add_co2(int *flavor_level,int co2_drink_power){
    int f_temp = *flavor_level;//*****why flavor_level不能直接除2。
    if(co2_drink_power<=f_temp){
        flavor_level += 2*co2_drink_power;
    }
    else if(((f_temp/2)<co2_drink_power)&&(co2_drink_power<=f_temp)){
        flavor_level += 3*co2_drink_power;
    }
    else if(co2_drink_power>f_temp){
        flavor_level += co2_drink_power;
    }
    printf("The flavor level increased %d!\n",*flavor_level);
}

int shake(int* flavor_level, int shake_sum){
    flavor_level += shake_sum;
    printf("The flavor level increased %d!\n",*flavor_level);
}

void pull_into_glass_message(){
    printf("Finally, select a wine glass to pull your cocktail in.\n");
    printf("Please enter the number of wine glass(1 to 5): ");
}

int pull_into_a_glass(int price, int cup_type, int flavor_level){
    if(cup_type == 1){
        printf("The price increased %d!",10);
        price = 10 + flavor_level;
    }
    else if(cup_type == 2){
        price = 15 + flavor_level;
        printf("The price increased %d!",15);
    }
    else if(cup_type == 3){
        price = 17 + flavor_level;
        printf("The price increased %d!",17);
    }
    else if(cup_type == 4){
        price = 23 + flavor_level;
        printf("The price increased %d!",23);
    }
    else if(cup_type == 5){
        price = 40 + flavor_level;
        printf("The price increased %d!",40);
    }
    printf("The Price of this cocktail is %d!",price);
}

int main(){
    int flavor_level=0, price=0;
    int base_flavor_level=0, wine_1=0, wine_2=0, shake_sum=0, shake_temp=0;
    int juice_flavor_level=0, co2_drink_power=0, cup_type=0;

    for(int i=0;i<2;i++){//the whole game
        if(i == 0) printf("Let's make our first cocktail!\n");
        if(i == 1) printf("Let's make our second cocktail!\n");
    
        //process of making a cocktail
        select_base_wine_message();
        scanf("%d",&base_flavor_level);
        select_the_base_wine(&flavor_level, base_flavor_level);
        
        for(int i=0;i<2;i++){
            add_two_wines_message();
            scanf("%d%d", &wine_1, &wine_2);
            add_two_wines(&flavor_level, wine_1, wine_2);
        }
        
        while(1){
            printf("Please enter the power of a shake(0 to stop): ");
            scanf("%d",&shake_temp);
            if(shake_temp==0) break;
            shake_sum += shake_temp;
        }
        shake(&flavor_level, shake_sum);

        add_juice_message();
        scanf("%d",&juice_flavor_level);
        add_juice(&flavor_level, juice_flavor_level);

        add_co2_mesage(flavor_level);
        scanf("%d",&co2_drink_power);
        add_co2(&flavor_level, co2_drink_power);

        pull_into_glass_message();
        scanf("%d", &cup_type);
        pull_into_a_glass(price,cup_type,flavor_level);
    }
}