/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 19:29:16 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"

int	main(int argc, char *argv[])
{
	t_scene		*scene;

	check_error(argc, argv);
	scene = scene_init();
	key_hook(scene);
	read_file(scene, argv[1]);
	print_count(scene);
	render(scene);
	mlx_loop(scene->mlx);
	return (0);
}
