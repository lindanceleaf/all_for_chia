#include <stdio.h>

int gcd(int a, int b){
    int r = a % b;
    a = b;
    b = r;
    if(!b) return a;
    else return gcd(a,b);
}

int main(){
    int i, j;
    scanf("%d %d", &i, &j);
    if(i == 0 || j == 0) printf("%d\n", i + j);
    else printf("%d\n", gcd(i, j));
}