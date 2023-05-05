/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/05 15:00:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_cam	cam;
	t_env	env;

	t_point3	lookfrom;
	t_point3	lookat;
	t_vec3		vup;
	double		dist_to_focus;
	double		aperture;

	init_img(&env);
	init_mlx(&env);
	init_world(&env);
	// env.world = random_scene();

	lookfrom = create_vec3_xyz(26, 3, 6);
	lookat = create_vec3_xyz(0, 2, 0);
	vup = create_vec3_xyz(0, 1, 0);
	dist_to_focus = 10.0;
	aperture = 0.1;
	cam = init_camera(lookfrom, lookat, vup, 20, env.img.aspect_ratio, aperture, dist_to_focus, 0.0, 1.0);
	render(&env, cam);
	mlx_loop(env.mlx.mlx);
	return (0);
}
