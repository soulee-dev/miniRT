#include "minirt.h"
// REMOVE BEFORE FLIGHT
double	random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double	random_double2(double min, double max)
{
	return (min + (max - min) * random_double());
}

t_vec3	random_vec3(void)
{
	return (create_vec3_xyz(random_double(), random_double(), random_double()));
}

t_vec3	random_vec3_2(double min, double max)
{
	return (create_vec3_xyz(random_double2(min, max),
			random_double2(min, max), random_double2(min, max)));
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	p;

	while (1)
	{
		p = random_vec3_2(-1, 1);
		if (length_squared(p) >= 1)
			continue ;
		return (p);
	}
}
// REMOVE BEFORE FLIGHT