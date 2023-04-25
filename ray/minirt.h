/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:40:55 by soulee            #+#    #+#             */
/*   Updated: 2023/04/25 20:29:17 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

void    render(int width, int height, void *mlx, void *mlx_win);
t_vec	add_vec(t_vec u, t_vec v);
t_vec	sub_vec(t_vec u, t_vec v);
t_vec	mul_vec(t_vec u, t_vec v);
t_vec	mul_n_vec(t_vec u, double n);
t_vec	div_vec(t_vec u, t_vec v);
t_vec	div_n_vec(t_vec u, double n);
double	dot(t_vec u, t_vec v);
float	length_squared(t_vec u);
float	length(t_vec u);
t_vec	unit_vector(t_vec v);
t_vec	create_vector(double n);