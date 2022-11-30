#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    long long int student_ID[N];
    int score[N];

    for(int i = 0; i < N; i++){
        scanf("%lld %d", &student_ID[i], &score[i]);
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if(score[j] < score[j + 1] || (score[j] == score[j + 1] && student_ID[j] > student_ID[j + 1])){
                int temp = score[j];
                long long int _temp = student_ID[j];
                score[j] = score[j + 1];
                student_ID[j] = student_ID[j + 1];
                score[j + 1] = temp;
                student_ID[j + 1] = _temp;
            }
        }
    }

    for(int i = 0; i < N; i++){
        printf("%lld %d\n", student_ID[i], score[i]);
    }
}