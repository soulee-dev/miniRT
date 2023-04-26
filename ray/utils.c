#include "minirt.h"

double  random_double()
{
    return rand() / (RAND_MAX + 1.0);
}

double  random_double2(double min, double max)
{
    return min + (max - min) * random_double();
}

double  clamp(double x, double min, double max)
{
    if (x < min) return min;
    if (x > max) return max;
    return x;
}
