/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:40:55 by soulee            #+#    #+#             */
/*   Updated: 2023/04/26 15:26:01 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>
# include <stdio.h>
# include <math.h>

enum e_keys{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ARROW_UP = 126,
	KEY_ARROW_DOWN = 125,
	X_EVENT_KEY_RELEASE = 3,
	X_EVENT_KEY_EXIT = 17
};

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_ray
{
	t_vec	orig;
	t_vec	dir;
}				t_ray;

typedef struct	s_sphere
{
	t_vec	center;
	double	radius;
}				t_sphere;

typedef struct	s_hittable_list
{
	t_sphere	sp[2];
}		t_hittable_list;

t_vec	add_vec(t_vec u, t_vec v);
t_vec	sub_vec(t_vec u, t_vec v);
t_vec	mul_vec(t_vec u, t_vec v);
t_vec	mul_n_vec(t_vec u, double n);
t_vec	div_vec(t_vec u, t_vec v);
t_vec	div_n_vec(t_vec u, double n);
float	length_squared(t_vec u);
float	length(t_vec u);
t_vec	unit_vector(t_vec v);
t_vec	create_vector(double n);
double	dot_vec(t_vec u, t_vec v);
t_vec	at(t_ray r, double t);


void    render(void *mlx, void *mlx_win, int image_width, int image_height, double aspect_ratio, t_vec origin);