/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 23:47:56 by soulee           ###   ########.fr       */
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
	cam = init_camera(90.0, env.img.aspect_ratio);
	render(&env, cam);
	mlx_loop(env.mlx.mlx);
	return (0);
}
