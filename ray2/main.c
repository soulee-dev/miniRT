/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/11 17:30:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_cam		cam;
	t_cam_env	cam_env;
	t_env		env;

	init_img(&env);
	init_mlx(&env);
	init_world(&env);
	env.background = create_vec3_t(0.0);
	// env.world = random_scene();
	cam_env.lookfrom = create_vec3_xyz(26, 10, 6);
	cam_env.lookat = create_vec3_xyz(0, -2, 0);
	cam_env.vup = create_vec3_xyz(0, 1, 0);
	cam_env.vfov = 20;
	cam_env.aspect_ratio = env.img.aspect_ratio;
	cam_env.aperture = 0.1;
	cam_env.dist_to_focus = 10.0;
	cam_env.time0 = 0.0;
	cam_env.time1 = 1.0;
	cam = init_camera(cam_env);
	render(&env, cam);
	mlx_loop(env.mlx.mlx);
	return (0);
}
