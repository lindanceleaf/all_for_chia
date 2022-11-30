#include <stdio.h>

int main(){
    double height, weight;
    scanf("%lf %lf", &height, &weight);

    height = (double)(int)(height) / 100;
    weight = (double)(int)(weight * 10) / 10;

    double BMI = weight / (height * height);
    
    if(height <= 1.57 || height >= 1.96) printf("MILITARY SERVICE EXEMPTION\n");
    else if(BMI < 16.5 || BMI > 31.5) printf("MILITARY SERVICE EXEMPTION\n");
    else if(BMI < 17 || BMI > 31) printf("ALTERNATIVE SERVICE\n");
    else printf("REGULAR SERVICE\n");
}