/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 19:17:55 by soulee           ###   ########.fr       */
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

void	test_scene(t_scene *scene)
{
	scene->world = 0;
	add_obj(&scene->world, object(SP, sphere(point3(0, 0, 0), 2), color(0.5, 0, 0)));
	add_obj(&scene->world, object(SP, sphere(point3(0, -1000, 0), 995), color(1, 1, 1)));
	add_obj(&scene->world, object(CY, cylinder(point3(2, -1, -5), vec3(0, 1, 0), 1, 5), color(0, 0.5, 0)));
	add_obj(&scene->world, object(PL, plane(point3(0, 0, 0), vec3(0, 1, 0)), color(0, 0, 1)));
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
	// test_scene(scene);
	render(scene);
	mlx_loop(scene->mlx);
	return (0);
}

// Normalize input direction vectors when input.