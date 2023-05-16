/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 20:05:11 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	main(void)
// {
// 	t_cam		cam;
// 	t_cam_env	cam_env;
// 	t_env		env;

// 	init_img(&env);
// 	init_mlx(&env);
// 	init_world(&env);
// 	// env.world = random_scene();
// 	cam_env.lookfrom = create_vec3_xyz(26, 10, 6);
// 	cam_env.lookat = create_vec3_xyz(0, -2, 0);
// 	cam_env.vup = create_vec3_xyz(0, 1, 0);
// 	cam_env.vfov = 20;
// 	cam_env.aspect_ratio = env.img.aspect_ratio;
// 	cam_env.aperture = 0.1;
// 	cam_env.dist_to_focus = 10.0;
// 	cam_env.time0 = 0.0;
// 	cam_env.time1 = 1.0;
// 	cam = init_camera(cam_env);
// 	render(&env, &cam);
// 	mlx_loop(env.mlx.mlx);
// 	return (0);
// }

void	exit_error(char *s)
{
	while (*s)
		write(2, s++, 1);
	write(2, "\n", 1);
	exit(1);
}

void	init_env(t_env *env)
{
	init_img(env);
	init_mlx(env);
}

int	main(int argc, char *argv[])
{
	t_env	env;
	t_cam	cam;

	ft_bzero(&env, sizeof(env));
	check_error(argc, argv);
	init_env(&env);
	read_file(&env, argv[1]);
	cam = init_camera(env.cam_env);
	render(&env, &cam);
	mlx_loop(env.mlx.mlx);
	return (0);
}
