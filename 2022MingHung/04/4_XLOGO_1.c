#include <stdio.h>

int main(){
    int H, W;
    scanf("%d %d", &W, &H);
    for(int i = 0; i < W; i++){
        if(H - 2 * (W + i) >= 0){
            for(int j = 0;j < W+i; j++){
                printf("*");
            }
            for(int j = 0;j < H - 2 * (W + i); j++){
                printf(" ");
            }
            for(int j = 0;j < W+i; j++){
                printf("*");
            }
            printf("\n");
        }
        else{
            for(int j = 0;j < H;j++){
                printf("*");
            }
            printf("\n");
        }
    }

    for(int i = 1;i <= (H-2*W-1) / 2  + 1;i++){
        for(int j = 0;j < i;j++){
            printf(" ");
        }
        int last_space = H - 2*i;
        if((2*W-1) * 2 <= last_space){
            for(int j = 0;j < (2*W-1);j++){
                printf("*");
            }
            for(int j = 0;j < last_space - 2 *(2*W-1);j++){
                printf(" ");
            }
            for(int j = 0;j < (2*W-1);j++){
                printf("*");
            }
        }
        else{
            for(int j = 0;j<last_space;j++){
                printf("*");
            }
        }
        printf("\n");
    }
    
    for(int i = (H-2*W-1)/2 ;  i > 0 ;i--){
        for(int j = 0;j<i;j++){
            printf(" ");
        }
        int last_space = H - 2*i;
        if((2*W-1) * 2 <= last_space){
            for(int j = 0;j < (2*W-1);j++){
                printf("*");
            }
            for(int j = 0;j < last_space - 2 *(2*W-1);j++){
                printf(" ");
            }
            for(int j = 0;j < (2*W-1);j++){
                printf("*");
            }
        }
        else{
            for(int j = 0;j<last_space;j++){
                printf("*");
            }
        }
        printf("\n");
    }

    for(int i = W-1;i >= 0;i--){
        if(2*(i+W) > H){
            for(int j = 0;j<H;j++){
                printf("*");
            }
        }
        else{
            for(int j = 0;j<i+W;j++){
                printf("*");
            }
            for(int j = 0;j<H-2*(i+W);j++){
                printf(" ");
            }
            for(int j = 0;j<i+W;j++){
                printf("*");
            }
        }
        printf("\n");
    }
}