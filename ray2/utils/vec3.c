/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:46:45 by soulee            #+#    #+#             */
/*   Updated: 2023/04/30 00:00:11 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	print_vec3(t_vec3 vec3)
{
	printf("x:%lf y:%lf z:%lf\n", vec3.x, vec3.y, vec3.z);
}

int	near_zero(t_vec3 u)
{
	double	s;

	s = 1e-8;
	return ((fabs(u.x) < s) && (fabs(u.y) < s) && (fabs(u.z) < s));
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (sub_vec3(v, mul_n_vec3(n, 2.0 * dot(v, n))));
}

t_vec3	refract(t_vec3 uv, t_vec3 n, double etai_over_etat)
{
	double	cos_theta;
	t_vec3	r_out_perp;
	t_vec3	r_out_parallel;

	cos_theta = fmin(dot(mul_n_vec3(uv, -1), n), 1.0);
	r_out_perp = mul_n_vec3(add_vec3(uv,
				mul_n_vec3(n, cos_theta)), etai_over_etat);
	r_out_parallel = mul_n_vec3(n,
			-sqrt(fabs(1.0 - length_squared(r_out_perp))));
	return (add_vec3(r_out_perp, r_out_parallel));
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	return (
		create_vec3_xyz(
			u.y * v.z - u.z * v.y,
			u.z * v.x - u.x * v.z,
			u.x * v.y - u.y * v.x
		)
	);
}
