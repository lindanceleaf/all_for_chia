#include <stdio.h>

int Fib(int i){
    if(i == 0) return 0;
    else if(i == 1) return 1;
    else return Fib(i - 1) + Fib(i - 2);
}

long long int combination(int n, int k){
    if(k == 0 || n == k) return 1;
    else if(k == 1 || k == n - 1) return n;
    else if(n == 1) return 1;
    else return combination(n - 1, k) + combination(n - 1, k - 1);
}

long long int quick_power(int x, int y, int m){
    if(y == 1) return x % m;
    else if(y % 2) return ((x * quick_power(x, (y - 1) / 2, m) * quick_power(x, (y - 1) / 2, m)) % m);
    else return ((quick_power(x, y / 2, m) * quick_power(x, y / 2, m)) % m);
}

void first_type(){
    int N;
    printf("Please enter N: ");
    scanf("%d", &N);

    long long int result = 1;
    for(int i = 1; i <= N; i++) result *= i;
    printf("%lld\n", result);
}

void second_type(){
    int i;
    printf("Please enter i: ");
    scanf("%d", &i);
    printf("%d\n", Fib(i));
}

void third_type(){
    int n, k;
    printf("Please enter n and k: ");
    scanf("%d %d", &n, &k);
    printf("%lld\n", combination(n, k));
}

void fourth_type(){
    int x, y, m;
    printf("Please enter x, y and m: ");
    scanf("%d %d %d", &x, &y, &m);
    printf("%lld\n", quick_power(x, y, m));
}

int main(){
    int question_number;
    printf("How many queries do you want: ");
    scanf("%d", &question_number);

    for(int i = 0; i < question_number; i++){
        int type_number;
        printf("Which type of query do you want: ");
        scanf("%d", &type_number);
        if(type_number == 1) first_type();
        else if(type_number == 2) second_type();
        else if(type_number == 3) third_type();
        else if(type_number == 4) fourth_type();
    }
}