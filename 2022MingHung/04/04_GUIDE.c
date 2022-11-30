#include <stdio.h>

int is_prime(int t){
    if(t < 2) return 0;
    else if(t == 2 || t == 3) return 1;
    else{
        for(int i = 2; i * i <= t; i++){
            if(t % i == 0) return 0;
        }
        return 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int num[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n; i++){
        if(is_prime(num[i])) printf("YES\n");
        else printf("NO\n");
    }
}