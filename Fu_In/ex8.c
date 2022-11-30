#include <stdio.h>

void first_cocktail(){
    printf("Let's make our first cocktail!\n");
}

void second_cocktail(){
    printf("Let's make our second cocktail!\n");
}

int select_base_wine(){
    printf("Let's select the base wine!\n");
    printf("Please Enter flavor level of the base wine: ");
    int b;
    scanf("%d", &b);
    printf("The flavor level is %d!\n",b);
    return b;
}

int gcd(int a, int b){
    int r = a % b;
    a = b;
    b = r;
    if(b) return gcd(a, b);
    else return a;
}

int add_two_wines(){
    printf("Now add two kinds of wines.\n");
    printf("Please Enter two types representing each wine: ");
    int w1, w2;
    scanf("%d %d", &w1, &w2);
    int gcf = gcd(w1, w2);
    printf("The flavor level increased %d!\n", gcf);
    return gcf;
}

int add_juice(){
    printf("Now add some juice.\n");
    printf("Please Enter flavor level of the juice: ");
    int j;
    scanf("%d", &j);
    printf("The flavor level increased %d!\n", j);
    return j;
}

int add_CO2(int current_flavor_level){
    printf("Now add some CO2.\n");
    printf("The current flavor level is %d.\n", current_flavor_level);
    printf("Please Enter power of CO2: ");
    int c;
    scanf("%d", &c);
    if(c <= (current_flavor_level / 2)) c *= 2;
    else if(c <= current_flavor_level) c *= 3;
    printf("The flavor level increased %d!\n", c);
    return c;
}

int shake(){
    printf("Now shake.\n");
    int cnt = 0;
    int s;
    do{
        printf("Please enter the power of a shake(0 to stop): ");
        scanf("%d", &s);
        cnt += s;
    }while(s);
    printf("The flavor level increased %d!\n", cnt);
    return cnt;
}

int pull_into_glass(){
    printf("Finally, select a wine glass to pull your cocktail in.\n");
    int t;
    printf("Please enter the number of wine glass(1 to 5): ");
    scanf("%d", &t);
    if(t == 1) t = 10;
    else if(t == 2) t = 15;
    else if(t == 3) t = 17;
    else if(t == 4) t = 23;
    else if(t == 5) t = 40;
    printf("The price increased %d!\n", t);
    return t;
}

void finish_wine(int price){
    printf("Well done! The Price of this cocktail is %d!\n", price);
}

int main(){
    int price;
    // do the first cocktail
    first_cocktail();
    price = 0;
    price += select_base_wine();
    price += add_two_wines();
    price += add_two_wines();
    price += shake();
    price += add_juice();
    price += add_CO2(price);
    price += pull_into_glass();
    finish_wine(price);

    // do the second cocktail
    second_cocktail();
    price = 0;
    price += select_base_wine();
    price += add_two_wines();
    price += shake();
    price += add_juice();
    price += shake();
    price += add_CO2(price);
    price += add_two_wines();
    price += add_CO2(price);
    price += add_juice();
    price += shake();
    price += add_two_wines();
    price += shake();
    price += add_two_wines();
    price += add_juice();
    price += add_CO2(price);
    price += shake();
    price += add_CO2(price);
    price += add_two_wines();
    price += shake();
    price += add_juice();
    price += add_juice();
    price += add_two_wines();
    price += add_two_wines();
    price += add_CO2(price);
    price += shake();
    price += add_two_wines();
    price += shake();
    price += add_two_wines();
    price += shake();
    price += pull_into_glass();
    finish_wine(price);
}