#include <stdio.h>

int GCD(int a, int b){
    int r = a % b;
    a = b;
    b = r;
    if(b) return GCD(a, b);
    else return a;
}

int main(){
    int N;
    while(1){
        scanf("%d", &N);
        if(!N) break;
        int G = 0;
        for(int i = 1; i < N; i++){
            for(int j = i + 1; j <= N; j++){
                G += GCD(i ,j);
            }
        }
        printf("%d\n", G);
    }
}