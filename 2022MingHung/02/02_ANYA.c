#include <stdio.h>

int main(){
    int total, now, target;
    scanf("%d %d %d", &total, &now, &target);
    if(now >= target) printf("%d\n", now - target);
    else printf("%d\n", now + total - target);
}