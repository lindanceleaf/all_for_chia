#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
    int alphabet[26] = {0};
    int bytes_count = 0;
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int whitespace_count = 0;
    int line_count = 0;
    bool check = false;

    char temp;
    while(1){
        temp = getchar();
        if(temp == 26){
            line_count++;
            break;
        }
        bytes_count++;
        if(isdigit(temp)) digit_count++;
        else if(isspace(temp)){
            whitespace_count++;
            if(temp == '\n') line_count++;
        }
        else if(isalpha(temp)){
            if(isupper(temp)) uppercase_count++;
            else if(islower(temp)) lowercase_count++;
            temp = toupper(temp);
            alphabet[temp - 65]++;
        }
    }

    printf("Bytes Count: %d\n", bytes_count);
    printf("Lowercase Count: %d\n", lowercase_count);
    printf("Uppercase Count: %d\n", uppercase_count);
    printf("Digit Count: %d\n", digit_count);
    printf("Whitespace Count: %d\n", whitespace_count);
    printf("Line Count: %d\n", line_count);
    for(int i = 0; i < 26; i++){
        printf("%c/%c: %d, %.3f\n", i + 65, i+ 97, alphabet[i], (float)alphabet[i] / (lowercase_count + uppercase_count));
    }
}