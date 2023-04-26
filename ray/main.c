/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:53:12 by soulee            #+#    #+#             */
/*   Updated: 2023/04/26 18:23:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>

int	key_hook(int key_code, t_env *env)
{
	printf("%d\n", key_code);
	if (key_code == KEY_W)
	{
		env->origin.z -= 0.1;
		render(env);
	}
	else if (key_code == KEY_S)
	{
		env->origin.z += 0.1;
		render(env);
	}
	else if (key_code == KEY_A)
	{
		env->origin.x -= 0.1;
		render(env);
	}
	else if (key_code == KEY_D)
	{
		env->origin.x += 0.1;
		render(env);
	}
	else if (key_code == KEY_ARROW_UP)
	{
		env->origin.y += 0.1;
		render(env);
	}
	else if (key_code == KEY_ARROW_DOWN)
	{
		env->origin.y -= 0.1;
		render(env);
	}
	return (0);
}

int	main(void)
{
	t_env	env;
	// Image
	env.aspect_ratio = 16.0 / 9.0;
	env.image_width = 1920;
	env.image_height = env.image_width / env.aspect_ratio;
	env.smaples_per_pixel = 1;

	env.mlx = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx, env.image_width, env.image_height, "miniRT-practice");
	
	env.origin.x = 0.0;
	env.origin.y = 0.0;
	env.origin.z = 0.0;

	render(&env);
	mlx_hook(env.mlx_win, X_EVENT_KEY_RELEASE, 0, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
