#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    long long int data[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &data[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            long long int temp;
            scanf("%lld", &temp);
            data[i][j] += temp;
        }
    }

    for(int i = 0; i < m; i++){
        printf("%lld", data[i][0]);
        for(int j = 1; j < n; j++){
            printf(" %lld", data[i][j]);
        }
        printf("\n");
    }
}