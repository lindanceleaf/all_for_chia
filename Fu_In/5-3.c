#include <stdio.h>

int GCD(int a, int b){
    int r = a % b;
    a = b;
    b = r;
    if(b) return GCD(a, b);
    else return a;
}

int find_inverse(int left, int right, int left_cnt[], int right_cnt[]){
    int quotion = left / right;
    int remainder = left % right;

    int temp[] = {left_cnt[0] - quotion * right_cnt[0], left_cnt[1] - quotion * right_cnt[1]};
    if(remainder == 1){
        return temp[0];
    }
    else{
        return find_inverse(right, remainder, right_cnt, temp);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(GCD(a, b) != 1) printf("Inverse doesn't exist\n");
        
        else{
            int a_cnt[] = {1, 0};
            int b_cnt[] = {0, 1};
            int temp = find_inverse(a, b, a_cnt, b_cnt);
            if(temp < 0){
                while(temp < 0) temp += b;
            }
            printf("multiplicative inverse is %d\n", temp);
        }
    }
}