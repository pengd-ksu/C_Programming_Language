#include <stdio.h>

#define LOWER   0       /* lower limit of table */
#define UPPER   300     /* upper limit */
#define STEP    20      /* step size*/

/* print Fahrenheit-Celsius table */
float celsius(float fahr);

int main()
{
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3.0f   %6.1f\n", fahr, celsius(fahr));
    return 0;
}

float celsius(float fahr)
{
    float celsius;
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}