#include <stdio.h>
#include <stdlib.h>

int main(){
    int row, column;
    scanf("%d %d", &row, &column);

    int **mines = malloc((row + 2) * sizeof(int *));
    for(int i = 0; i < row + 2; i++) mines[i] = calloc((column + 2), sizeof(int));

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            int temp;
            scanf("%d", &temp);
            if(temp == 1){
                for(int a = i - 1; a <= i + 1; a++){
                    for(int b = j - 1; b <= j + 1; b++){
                        mines[a][b]++;
                    }
                }
                mines[i][j] = -100;
            }
        }
    }

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            if(j != 1)printf(" ");
            printf("|| :");
            if(mines[i][j] < 0)printf("boom");
            else switch(mines[i][j]){
                case 0:
                    printf("zero");
                    break;
                case 1:
                    printf("one");
                    break;
                case 2:
                    printf("two");
                    break;
                case 3:
                    printf("three");
                    break;
                case 4:
                    printf("four");
                    break;
                case 5:
                    printf("five");
                    break;
                case 6:
                    printf("six");
                    break;
                case 7:
                    printf("seven");
                    break;
                case 8:
                    printf("eight");
                    break;
            }
            printf(": ||");
        }
        printf("\n");
    }
}