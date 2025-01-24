#include <float.h>
#include <stdio.h>

#define PI 3.14159

#define STEP 0.001
#define TO 5

long double minRadius(long double from, long double to, long double step);
long double calcArea(long double r);
long double calcHeight(long double r);

int main(int argc, char const *argv[])
{
    const long double minR = minRadius(STEP, TO, STEP);
    const long double minH = calcHeight(minR);
    const long double minA = calcArea(minR);

    printf("r = %Lf; h = %Lf => a = %Lf \n", minR, minH, minA);

    return 0;
}

long double minRadius(long double from, long double to, long double step)
{
    long double min = 0;
    long double minA = LDBL_MAX;

    int nextPrint = 1;

    for (long double r = from; r <= to; r += step)
    {
        if (r >= nextPrint) {
            printf("At %d\n", nextPrint);
            nextPrint++;
        }

        const long double a = calcArea(r);

        if (a < minA)
        {
            min = r;
            minA = a;
        }
    }

    return min;
}

long double calcArea(long double r)
{
    return 2 * PI * r * r + 660 / r;
}

long double calcHeight(long double r)
{
    return 330 / (PI * r * r);
}