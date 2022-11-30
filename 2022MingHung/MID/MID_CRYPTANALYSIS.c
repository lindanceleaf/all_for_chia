#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int N;
    int cnt[26] = {0};
    scanf("%d", &N);
    char text[500];
    for(int i = 0; i < N; i++){
        fgets(text, 500, stdin);
        int l = strlen(text);
        for(int j = 0; j < l; j++){
            if(isalpha(text[j])){
                text[j] = toupper(text[j]);
                cnt[text[j] - 65]++;
            }
        }
    }
    int max = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > max) max = cnt[i];
    }

    for(int i = max; i > 0; i++){
        for(int j = 0; j < 26; j++){
            if(cnt[j] == i){
                printf("%c %d\n", j + 65, i);
            }
        }
    }
}