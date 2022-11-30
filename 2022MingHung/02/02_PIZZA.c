#include <stdio.h>

int main(){
    int total_num, pizza_num;
    scanf("%d %d", &total_num, &pizza_num);

    printf("%d\n", pizza_num % total_num);
}