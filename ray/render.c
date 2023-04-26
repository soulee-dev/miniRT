/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:48:50 by soulee            #+#    #+#             */
/*   Updated: 2023/04/26 15:14:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "progress/progress.h"

double	hit_sphere(t_sphere s, t_ray r)
{
	t_vec	oc = sub_vec(r.orig, s.center);
	float	a = length_squared(r.dir);
	float	half_b = dot_vec(oc, r.dir);
	float	c = length_squared(oc) - s.radius * s.radius;
	float	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a); 

}

t_vec	ray_color(t_ray r, t_hittable_list world)
{
	float	t = hit_sphere(world.sp[0], r);
	if (t > 0.0)
	{
		t_vec	n = unit_vector(sub_vec(at(r, t), world.sp[0].center));
		t_vec	color;

		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;
		return (mul_n_vec(color, 0.5));
	}
	t = hit_sphere(world.sp[1], r);
	if (t > 0.0)
	{
		t_vec	n = unit_vector(sub_vec(at(r, t), world.sp[1].center));
		t_vec	color;

		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;
		return (mul_n_vec(color, 0.5));
	}
	t_vec	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	t_vec	a = create_vector(1.0);
	t_vec	b = {0.5, 0.7, 1.0};
	return (add_vec(mul_n_vec(a, 1.0 -t), mul_n_vec(b, t)));
}

typedef struct	s_hit_record
{
	t_vec	p;
	t_vec	normal;
	double	t;
	int		front_face;
}				t_hit_record;

void	set_face_normal(t_vec direction, t_vec normal, t_vec outward_normal, int front_face)
{
	front_face = dot_vec(direction, outward_normal) < 0 ? 1 : 0;
	normal = front_face ? outward_normal : mul_n_vec(outward_normal, -1);
}

int	hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_sphere s)
{
	t_vec	oc = sub_vec(r.orig, s.center);
	float	a = length_squared(r.dir);
	float	half_b = dot_vec(oc, r.dir);
	float	c = length_squared(oc) - s.radius * s.radius ;
	float	discriminant = half_b * half_b - a * c;

	if (discriminant > 0)
	{
		float	root = sqrt(discriminant);
		float	temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = at(r, rec.t);
			t_vec	outward_normal = div_n_vec(sub_vec(rec.p, s.center), s.radius);
			set_face_normal(r.dir, rec.normal, outward_normal, rec.front_face);
			return (1);	
		}
		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = at(r,rec.t);
			t_vec	outward_normal = div_n_vec(sub_vec(rec.p, s.center), s.radius);
			set_face_normal(r.dir, rec.normal, outward_normal, rec.front_face);
			return (1);
		}
	}
	return (0);
}

int	hittable_list_hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_hittable_list world)
{
	t_hit_record	temp_rec;
	int				hit_anything = 0;
	float			closest_so_far = t_max;

	int				i = 0;
	while (i < 2)
	{
		if (hit(r, t_min, closest_so_far, temp_rec, world.sp[i]))
		{
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}


int	rgb_to_int(t_vec c)
{
    int color = 0;
	int	ir = 255.999 * c.x;
	int	ig = 255.999 * c.y;
	int	ib = 255.999 * c.z;

	color = ir * 256 * 256 + ig * 256 + ib;
    return (color);
}

void    render(void *mlx, void *mlx_win, int image_width, int image_height, double aspect_ratio, t_vec origin)
{
	// World
	t_hittable_list	world;

	world.sp[0].center.x = 0;
	world.sp[0].center.y = 0;
	world.sp[0].center.z = -1;
	world.sp[0].radius = 0.5;

	world.sp[1].center.x = 0;
	world.sp[1].center.y = -100.5;
	world.sp[1].center.z = -1;
	world.sp[1].radius = 100;

	// Camera
	// viewport란 3D 에서 평면으로 보이게 되는 부분
	double	viewport_height = 2.0;
	double	viewport_width = aspect_ratio * viewport_height;
	double	focal_length = 1.0;

	t_vec	horizontal = {viewport_width, 0, 0};
	t_vec	vertical = {0, viewport_height, 0};
	t_vec	any = {0, 0, focal_length};
	t_vec	lower_left_coner = sub_vec(origin, add_vec(add_vec(div_n_vec(horizontal, 2), div_n_vec(vertical, 2)), any));

	t_progress progress = create_progress(image_height * image_width, 5);
	// Render
	printf("Render Start\n");
	int	count = 0;
	for (int i = 0; i < image_width; i++)
	{
		for (int j = 0; j < image_height; j++)
		{
			// update_progress(&progress, count);
			double	u = (double)i / (image_width - 1);
			double	v = (image_height - (double)j - 1) / (image_height - 1);

			t_ray	r;
			r.orig = origin;
			r.dir = add_vec(lower_left_coner, add_vec(mul_n_vec(horizontal, u), mul_n_vec(sub_vec(vertical, origin), v)));
			t_vec	pixel_color = ray_color(r, world);
			mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(pixel_color));
			count++;
		}
	}
	printf("Done!\n");
}
