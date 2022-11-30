#include <stdio.h>
#include <stdlib.h>

int main(){
    int w,h;
    scanf("%d %d", &w, &h);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < h; j++){
            if((j-i <= w-1 && j-i >= -(w-1))|| (j+i >= h-w && j+i <= w+h-2)) printf("*");
            else{
                if(i >= w && i < h-w && j > h/2) break;
                else printf(" ");
            }
        }
        printf("\n");
    }
}