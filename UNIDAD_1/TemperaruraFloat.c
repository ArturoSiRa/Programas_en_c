#include <stdio.h>
/*Imprime la tabla de Fahreheit-Celsius
para farh = 0, 20, ..., 300.*/
int main()
{
    float farh, celsius;
    int lower, upper, step;
    
    lower =0;
    upper = 300;
    step = 20;

    farh = lower;
    while (farh <= upper)
    {
        celsius = 5 * (farh - 32) /9;
        printf("%3.0f%6.1f\n", farh, celsius);
        farh = farh + step;
    }
    
    return 0;
}
