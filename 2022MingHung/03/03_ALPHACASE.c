#include <stdio.h>
#include <ctype.h>

int main(){
    char data[5];
    scanf("%c", &data[0]);
    for(int i = 1; i < 5; i++){
        getchar();
        scanf("%c", &data[i]);
    }
    for(int i = 0; i < 5; i++){
        if(isalpha(data[i])){
            if(data[i] <= 90) printf("%c", tolower(data[i]));
            else printf("%c", toupper(data[i]));
        }
        else printf("%c", data[i]);
        if(i != 4) printf(" ");
        else printf("\n");
    }

}