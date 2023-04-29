/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/04/30 00:24:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_cam	cam;
	t_env	env;

	init_img(&env);
	init_mlx(&env);
	init_world(&env);
	cam = init_camera(create_vec3_xyz(-2, 2, 1), create_vec3_xyz(0, 0, -1), create_vec3_xyz(0, 1, 0), 90, env.img.aspect_ratio);
	render(&env, cam);
	mlx_loop(env.mlx.mlx);
	return (0);
}
