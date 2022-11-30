#include <stdio.h>
#include <stdbool.h>

bool is_happy_number(int cmp, int n){
    int temp = 0;
    while(n){
        temp += ((n % 10) * (n % 10));
        n /= 10;
    }
    if(temp == 1) return true;
    else if(temp == cmp) return false;
    else return is_happy_number(cmp, temp);
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        int n;
        scanf("%d", &n);
        if(is_happy_number(n, n)) printf("Case #%d: %d is a Happy number.\n", i, n);
        else printf("Case #%d: %d is an Unhappy number.\n", i, n);
    }
}