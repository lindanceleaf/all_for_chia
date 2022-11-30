#include <stdio.h>
#include <ctype.h>

int main(){
    char temp;
    long long int vowel = 0;
    long long int word = 0;
    _Bool is_word = 0;
    while(scanf("%c", &temp) != EOF && temp != '\n'){
        if(temp != ' '){
            is_word = 1;
            temp = toupper(temp);
            switch(temp){
                case 'A': case 'E': case 'I': case 'O': case 'U':
                vowel ++;
            }
        }
        else{
            if(is_word) word++;
            is_word = 0;
        }
    }
    printf("%lld %lld\n", vowel, word + 1);
}