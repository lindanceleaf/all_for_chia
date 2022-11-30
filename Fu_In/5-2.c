#include <stdio.h>

int fib(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        printf("%d = ",t);
        int biggest_num = 0;
        while(fib(biggest_num + 1) <= t) biggest_num++;
        for(int j = biggest_num; j > 1; j--){
            if(t >= fib(j)){
                printf("1");
                t -= fib(j);
            }
            else printf("0");
        }
        printf(" (fib)\n");
    }
}