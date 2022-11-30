#include <stdio.h>

int main(){
    int h, w;
    scanf("%d %d", &w, &h);
    // upper v
    for(int i = 0; i < w; i++){
        if(2 * (h + i) > w){
            for(int j = 0; j < w; j++) printf("*");
        }
        else{
            for(int j = 0; j < h + i; j++) printf("*");
            for(int j = 0; j < w - 2 * (h + i); j++) printf(" ");
            for(int j = 0; j < h + i; j++) printf("*");
        }
        printf("\n");
    }

    // upper v with start with space
    for(int i = 0; i < (w - 2 * h + 1) / 2 ; i++){
        for(int j = 0; j < i + 1; j++) printf(" ");
        for(int j = 0; j < w - 2 * (i + 1); j++) printf("*");
        printf("\n");
    }

    // lower v with start with space
    for(int i = (w - 2 * h) / 2; i >= 0; i--){
        for(int j = 0; j < i + 1; j++) printf(" ");
        for(int j = 0; j < w - 2 * (i + 1); j++) printf("*");
        printf("\n");
    }

    // lower v
    for(int i = w - 1; i >= 0; i--){
        if(2 * (h + i) > w){
            for(int j = 0; j < w; j++) printf("*");
        }
        else{
            for(int j = 0; j < h + i; j++) printf("*");
            for(int j = 0; j < w - 2 * (h + i); j++) printf(" ");
            for(int j = 0; j < h + i; j++) printf("*");
        }
        printf("\n");
    }
}