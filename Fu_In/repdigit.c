#include <stdio.h>

int main(){
    long long int n;
    scanf("%lld", &n);

    int data[10] = {0};
    while(n){
        int temp = n % 10;
        data[temp]++;
        n /= 10;
    }

    printf("0");
    for(int i = 1; i < 10; i++){
        printf(" %d", i);
    }
    printf("\n%d", data[0]);
    for(int i = 1; i < 10; i++){
        printf(" %d", data[i]);
    }
    printf("\n");
}