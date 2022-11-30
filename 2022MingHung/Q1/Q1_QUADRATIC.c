#include <stdio.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double discriminant = b * b - 4 * a * c;
    if(discriminant == 0) printf("DOUBLE ROOT\n");
    else if(discriminant > 0) printf("TWO REAL ROOTS\n");
    else printf("TWO COMPLEX ROOTS\n");
}