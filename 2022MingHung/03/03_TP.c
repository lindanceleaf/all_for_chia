#include <stdio.h>
#include <math.h>

int main(){
    float x, y, z;
    scanf("%f %f %f\n", &x, &y, &z);
    float f_x, f_y, f_z;
    scanf("/tp %f %f %f", &f_x, &f_y, &f_z);
    float sum = pow(f_x - x, 2) + pow(f_y - y, 2) + pow(f_z - z, 2);
    printf("%.2f\n", sqrt(sum));
}