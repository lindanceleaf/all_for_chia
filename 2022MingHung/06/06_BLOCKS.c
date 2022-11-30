#include <stdio.h>

int main(){
    int set_number = 1;
    while(1){
        int n;
        scanf("%d", &n);
        if(!n) break;
        else if(set_number != 1) printf("\n");

        int data[n];
        int summary = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &data[i]);
            summary += data[i];
        }

        int average = summary / n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(data[i] > average) cnt += (data[i] - average);
        }

        printf("Set #%d\n", set_number);
        printf("The minimum number of moves is %d.\n", cnt);
        set_number++;
    }
}