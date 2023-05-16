/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 20:20:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	init_world(&env);
	render(&env, &cam);
	mlx_loop(env.mlx.mlx);
	return (0);
}
