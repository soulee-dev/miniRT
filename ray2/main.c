/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/04/27 17:04:27 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_img(t_env *env)
{
	env->img.aspect_ratio = 16.0 / 9.0;
	env->img.width = WIDTH;
	env->img.height = env->img.width / env->img.aspect_ratio;
	// env->img.samples_per_pixel = 1;
	// env->img.max_depth = 50;
}

void	init_mlx(t_env *env)
{
	env->mlx.mlx = mlx_init();
	env->mlx.win = mlx_new_window(env->mlx.mlx, env->img.width,
			env->img.height, TITLE);
}

void	init_cam(t_env *env)
{
	env->cam.origin.x = 0.0;
	env->cam.origin.y = 0.0;
	env->cam.origin.z = 0.0;
	env->cam.viewport_height = 4.0;
	env->cam.viewport_width = env->img.aspect_ratio * env->cam.viewport_height;
	env->cam.focal_lenght = 1.0;
}

int	main(void)
{
	t_env	env;

	init_img(&env);
	init_cam(&env);
	init_mlx(&env);
	// render(&env);
	mlx_loop(env.mlx.mlx);
	return (0);
}
