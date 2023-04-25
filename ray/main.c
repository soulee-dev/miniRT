/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:53:12 by soulee            #+#    #+#             */
/*   Updated: 2023/04/25 23:18:47 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "progress/progress.h"

double	hit_sphere(t_vec center, double radius, t_vec origin, t_vec direction)
{
	t_vec	oc = sub_vec(origin, center);
	double	a = dot_vec(direction, direction);
	double	b = 2.0 * dot_vec(oc, direction);
	double	c = dot_vec(oc, oc) - radius * radius;
	double	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
	// return (discriminant > 0 ? 1 : 0);
}

t_vec	ray_color(t_vec origin, t_vec direction)
{
	t_vec	sphere = {0, 0, -1};
	double	t = hit_sphere(sphere, 0.5, origin, direction);
	if (t > 0.0)
	{
		t_vec	N = unit_vector(sub_vec(at(origin, direction, t), sphere));
		t_vec	color;

		color.x = N.x + 1;
		color.y = N.y + 1;
		color.z = N.z + 1;

		return (mul_n_vec(color, 0.5));
	}

	t_vec	unit_direction = unit_vector(direction);
	t = 0.5 * (unit_direction.y + 1.0);

	t_vec	a = create_vector(1.0);
	t_vec	b = {0.5, 0.7, 1.0};

	return (add_vec(mul_n_vec(a, 1.0 - t), mul_n_vec(b, t)));
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	// Image
	double	aspect_ratio = 16.0 / 9.0;
	int		image_width = 1000;
	int		image_height = image_width / aspect_ratio;
	
	// Camera
	// viewport란 3D 에서 평면으로 보이게 되는 부분
	double	viewport_height = 2.0;
	double	viewport_width = aspect_ratio * viewport_height;
	double	focal_length = 1.0;

	t_vec	origin = {0, 0.5, 0};
	t_vec	horizontal = {viewport_width, 0, 0};
	t_vec	vertical = {0, viewport_height, 0};
	t_vec	any = {0, 0, focal_length};
	t_vec	lower_left_coner = sub_vec(origin, add_vec(add_vec(div_n_vec(horizontal, 2), div_n_vec(vertical, 2)), any));

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, image_width, image_height, "miniRT-practice");
	// void *mlx_img = mlx_new_image(mlx, image_width, image_height);

	t_progress progress = create_progress(image_height * image_width, 5);
	// Render
	int	count = 0;
	for (int i = 0; i < image_width; i++)
	{
		for (int j = 0; j < image_height; j++)
		{
			// update_progress(&progress, count);
			double	u = (double)i / (image_width - 1);
			double	v = (image_height - (double)j - 1) / (image_height - 1);

			t_vec	a = origin;
			t_vec	b = add_vec(lower_left_coner, add_vec(mul_n_vec(horizontal, u), mul_n_vec(sub_vec(vertical, origin), v)));
			t_vec	pixel_color = ray_color(a, b);

			mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(pixel_color));
			count++;
		}
	}
	fprintf(stdout, "\n");
	mlx_loop(mlx);
	return (0);
}
