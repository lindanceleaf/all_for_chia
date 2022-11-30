#include <stdio.h>

int main(){
    unsigned long long int distance;
    scanf("%llu", &distance);

    unsigned long long int oil = 0;
    for(int i = 0; i < 5; i++){
        unsigned long long int temp;
        scanf("%llu", &temp);
        oil += temp;
    }

    if(distance > oil) printf("NO\n");
    else{
        unsigned long long int temp = distance;
        oil -= distance;
        if(oil >= temp) printf("YES\n");
        else printf("NO\n");
    }
}