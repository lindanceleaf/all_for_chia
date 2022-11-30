#include <stdio.h>

int main(){
    int data[6] = {302, 124, 90, 66, 24, 1};
    char str[6][10] = {"Darada", "Coco", "Luna", "TMT", "Kanata", "Min"};

    int h, m;
    scanf("%d %d", &h, &m);
    if(h == 0 && m == 0) printf("0 Min\n");
    else{
        int sum = m + 60 * h;
        for(int i = 0; i < 6; i++){
            if(sum >= data[i]){
                printf("%d %s", sum / data[i], str[i]);
                sum %= data[i];
                if(sum > 0) printf(" ");
            }
        }
    }
}