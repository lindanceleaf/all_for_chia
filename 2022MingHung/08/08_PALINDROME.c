#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char original_string[200000];

    char temp;
    int cnt = 0;
    while(scanf("%c", &temp) != EOF){
        temp = toupper(temp);
        if((temp >= 65 && temp <= 90)){
            original_string[cnt] = temp;
            cnt ++;
        }
    }
    original_string[cnt] = '\0';

    int len = strlen(original_string);
    _Bool is_palindrome = 1;
    for(int i = 0; i <= len / 2; i++){
        if(original_string[i] != original_string[len - 1 - i]){
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome) printf("YES\n");
    else printf("NO\n");
}