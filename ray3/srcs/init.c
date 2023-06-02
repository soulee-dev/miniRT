/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:24:10 by soulee            #+#    #+#             */
/*   Updated: 2023/06/02 15:10:20 by soulee           ###   ########.fr       */
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
	// scene->canvas = canvas(1000, 560);
	scene->canvas = canvas(400, 300);
	scene->mlx = mlx_init();
	scene->mlx_win = mlx_new_window(scene->mlx, scene->canvas.width, \
		scene->canvas.height, TITLE);
	return (scene);
}

int	check_key(t_scene *scene, int key)
{
	if (key == KEY_W)
		scene->lookfrom.x -= 0.5;
	else if (key == KEY_S)
		scene->lookfrom.x += 0.5;
	else if (key == KEY_A)
		scene->lookfrom.z += 0.5;
	else if (key == KEY_D)
		scene->lookfrom.z -= 0.5;
	else if (key == KEY_ARROW_UP)
		scene->lookat.y += 0.5;
	else if (key == KEY_ARROW_DOWN)
		scene->lookat.y -= 0.5;
	else if (key == KEY_ARROW_LEFT)
		scene->lookat.z += 0.5;
	else if (key == KEY_ARROW_RIGHT)
		scene->lookat.z -= 0.5;
	else
		return (0);
	return (1);
}

int	key_down(int key, t_scene *scene)
{
	if (key == KEY_ESC)
		quit();
	if (scene->is_rendered)
	{
		if (check_key(scene, key))
		{
			printf("lookfrom: ");
			print_vec3(scene->lookfrom);
			printf("lookat:   ");
			print_vec3(scene->lookat);
			scene->camera = camera(&scene->canvas, \
				scene->lookfrom, scene->lookat, scene->vfov);
			render(scene);
		}
	}
	return (0);
}

void	key_hook(t_scene *scene)
{
	mlx_hook(scene->mlx_win, DESTROY, 0, quit, NULL);
	mlx_hook(scene->mlx_win, KEYDOWN, 0, key_down, scene);
}

void	print_count(t_scene *scene)
{
	printf("\n");
	printf("Ambient Light:%zu\n", scene->count.ambient_light);
	printf("Camera:%zu\n", scene->count.camera);
	printf("Light:%zu\n", scene->count.light);
	printf("Sphere:%zu\n", scene->count.sphere);
	printf("Plane:%zu\n", scene->count.plane);
	printf("Cylinder:%zu\n", scene->count.cylinder);
}
