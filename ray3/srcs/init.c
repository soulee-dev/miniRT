/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:24:10 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 19:28:53 by soulee           ###   ########.fr       */
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

void	print_count(t_scene *scene)
{
	printf("Ambient Light:%zu\n", scene->count.ambient_light);
	printf("Camera:%zu\n", scene->count.camera);
	printf("Light:%zu\n", scene->count.light);
	printf("Sphere:%zu\n", scene->count.sphere);
	printf("Plane:%zu\n", scene->count.plane);
	printf("Cylinder:%zu\n", scene->count.cylinder);
}
