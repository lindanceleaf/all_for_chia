#include <stdio.h>

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int older_rabbits = 0;
        int young_rabbits = 2;
        for(int i = 0; i < N; i++){
            int born_rabbits = older_rabbits;
            older_rabbits += young_rabbits;
            young_rabbits = born_rabbits;
        }
        printf("%d\n", older_rabbits + young_rabbits);
    }
}