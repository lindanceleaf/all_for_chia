#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;

    fp = fopen("test.txt", "a+");
    fprintf(fp, "");
    fclose(fp);
}