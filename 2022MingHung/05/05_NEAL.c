#include <stdio.h>

int gcd(int a, int b){
    int r = a % b;
    a = b;
    b = r;
    if(r) return gcd(a, b);
    else return a;
}

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        int lcm = a * b / gcd(a,b);
        printf("%d\n", 1 + 364 / lcm);
    }
}