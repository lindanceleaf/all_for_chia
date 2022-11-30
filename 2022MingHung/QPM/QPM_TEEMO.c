#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int place[n];
    for(int i = 0; i < n; i++) scanf("%d", &place[i]);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(place[j] > place[j + 1]){
                int t = place[j];
                place[j] = place[j + 1];
                place[j + 1] = t;
            }
        }
    }

    int range = place[n - 1] - place[0];
    int radius = range / k;
    int max = place[n - 1], min = place[0];
    while(1){
        radius--;
        int target = -1;
        for(int i = 0; i < k; i++){
            int head;
            int left = 0, right = n - 1;
            if(i == 0) head = place[0];
            else{
                while(1){
                    int mid = left + (right - left) / 2;
                    if(place[mid] < target) left = mid;
                    else if(place[mid] >= target && place[mid - 1] < target){
                        head = place[mid];
                        break;
                    }
                    else right = mid;
                }
            }
            target = head + radius;
        }
        if(target < place[n-1]) break;
    }

    printf("%d\n", radius + 1);
}