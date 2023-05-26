/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 19:20:41 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		exit_error("error: malloc failed (scene)");
	ft_bzero(scene, sizeof(t_scene));
	ft_bzero(&scene->count, sizeof(t_count));
	scene->canvas = canvas(400, 300);
	scene->mlx = mlx_init();
	scene->mlx_win = mlx_new_window(scene->mlx, scene->canvas.width, \
		scene->canvas.height, TITLE);
	return (scene);
}

int	quit(void)
{
	exit(0);
}

int	key_down(int key, t_scene *scene)
{
	(void) scene;
	if (key == KEY_ESC || key == KEY_Q)
		quit();
	return (0);
}

void	key_hook(t_scene *scene)
{
	mlx_hook(scene->mlx_win, DESTROY, 0, quit, NULL);
	mlx_hook(scene->mlx_win, KEYDOWN, 0, key_down, scene);
}

int	main(int argc, char *argv[])
{
	t_scene		*scene;

	check_error(argc, argv);
	scene = scene_init();
	key_hook(scene);
	read_file(scene, argv[1]);
	render(scene);
	mlx_loop(scene->mlx);
	return (0);
}

// Normalize input direction vectors when input.