#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int size;
        scanf("%d", &size);

        int num[2][size];
        for(int j = 0; j < size; j++){
            scanf("%d %d", &num[0][j], &num[1][j]);
        }

        for(int j = size - 1; j >= 0; j--){
            num[0][j] = num[0][j] + num[1][j];
            if(num[0][j] >= 10){
                num[0][j] -= 10;
                num[0][j-1]++;
            }
        }

        for(int j = 0; j < size; j++){
            printf("%d",num[0][j]);
        }
        printf("\n");

        if(i != N - 1) printf("\n");
    }
}