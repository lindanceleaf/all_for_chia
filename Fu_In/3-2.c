#include <stdio.h>
#include <ctype.h>

int main(){
    char temp;
    int sum = 0;
    while(1){
        if(scanf("%c", &temp) == EOF || !isalpha(temp)) break;
        temp = tolower(temp);
        switch(temp){
            case 'a': case 'e': case 'i': case 'l': case 'n': case 'o': case 'r': case 's': case 't': case 'u':
                sum ++; 
                break;
            case 'd': case 'g':
                sum += 2;
                break;
            case 'b': case 'c': case 'm': case 'p':
                sum += 3;
                break;
            case 'f': case 'h': case 'v': case 'w': case 'y':
                sum += 4;
                break;
            case 'k':
                sum += 5;
                break;
            case 'j': case 'x':
                sum += 8;
                break;
            case 'q': case 'z':
                sum += 10;
                break;
        }
    }
    printf("%d", sum);
}