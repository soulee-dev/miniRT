/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/15 13:58:14 by soulee           ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

void	exit_error(char *s)
{
	while (*s)
		write(2, s++, 1);
	write(2, "\n", 1);
	exit(1);
}

void	check_error(int argc, char *argv[])
{
	size_t	len;

	if (argc != 2)
		exit_error("error: Too little/many arguments");
	len = ft_strlen(argv[1]);
	if (len < 3)
		exit_error("error: Invalid file name");
	if (argv[1][len - 3] != '.'
		|| argv[1][len - 2] != 'r'
		|| argv[1][len - 1] != 't')
		exit_error("error: Invalid file name");
}

int	main(int argc, char *argv[])
{
	// t_env	env;

	check_error(argc, argv);
}
