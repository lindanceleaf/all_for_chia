#include <stdio.h>

int main(){
    int h,m,s;
    scanf("%d:%d:%d", &h,&m,&s);

    if(h >= 12) h -= 12;
    float m_a = m * 6;
    m_a += (0.1 * s);

    float h_a = h * 30;
    h_a += (m * 0.5);
    h_a += (s * (0.5 / 60));

    float result = h_a - m_a;
    result = result > 0 ? result : -result;
    printf("%.3f\n", result > 180 ? 360 - result : result);
}