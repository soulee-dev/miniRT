#include "minirt.h"

t_vec	add_vec(t_vec u, t_vec v)
{
	t_vec	new_vec;

	new_vec.x = u.x + v.x;
	new_vec.y = u.y + v.y;
	new_vec.z = u.z + v.z;
	return (new_vec);	
}

t_vec	sub_vec(t_vec u, t_vec v)
{
	t_vec	new_vec;

	new_vec.x = u.x - v.x;
	new_vec.y = u.y - v.y;
	new_vec.z = u.z - v.z;
	return (new_vec);	
}

t_vec	mul_vec(t_vec u, t_vec v)
{
	t_vec	new_vec;

	new_vec.x = u.x * v.x;
	new_vec.y = u.y * v.y;
	new_vec.z = u.z * v.z;
	return (new_vec);
}

t_vec	mul_n_vec(t_vec u, double n)
{
	t_vec	new_vec;

	new_vec.x = u.x * n;
	new_vec.y = u.y * n;
	new_vec.z = u.z * n;
	return (new_vec);
}

t_vec	div_vec(t_vec u, t_vec v)
{
	t_vec	new_vec;

	new_vec.x = u.x / v.x;
	new_vec.y = u.y / v.y;
	new_vec.z = u.z / v.z;
	return (new_vec);
}

t_vec	div_n_vec(t_vec u, double n)
{
	t_vec	new_vec;

	new_vec.x = u.x / n;
	new_vec.y = u.y / n;
	new_vec.z = u.z / n;
	return (new_vec);
}

double	dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

float	length_squared(t_vec u)
{
	return (u.x * u.x + u.y * u.y + u.z * u.z);
}

float length(t_vec u)
{
	return (sqrt(length_squared(u)));
}

t_vec	unit_vector(t_vec v)
{
	return (div_n_vec(v, length(v)));
}

t_vec	create_vector(double n)
{
	t_vec	new_vec;

	new_vec.x = n;
	new_vec.y = n;
	new_vec.z = n;
	return (new_vec);
}
