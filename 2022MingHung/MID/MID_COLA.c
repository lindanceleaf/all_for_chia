#include <stdio.h>

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int cnt = N;
        int full = 0;
        int empty = N;
        while(empty >= 3){
            full = empty / 3;
            empty %= 3;
            cnt += full;
            empty += full;
        }

        int _cnt = N;
        full = 0;
        empty = N + 1;
        while(empty >= 3){
            full = empty / 3;
            empty %= 3;
            _cnt += full;
            empty += full;
        }

        if(cnt == _cnt) printf("%d\n", cnt);
        else printf("%d\n", _cnt);
    }
}