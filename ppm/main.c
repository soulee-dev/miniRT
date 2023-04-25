/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:53:12 by soulee            #+#    #+#             */
/*   Updated: 2023/04/25 18:58:58 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rgt_to_int(double r, double g, double b)
{
    int color = 0;

    color |= (int)(b);
    color |= (int)(g) << 8;
    color |= (int)(r) << 16;
    return (color);
}

int	main(void)
{
	int		width = 3840;
	int		height = 2160;
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "miniRT-practice");
	for (int i = 0; i < height; i++)
	{
		fprintf(stdout, "\r%d%% | %d / %d", (int)(((double)(i + 1) / (double)height) * 100), i + 1, height);
		fflush(stdout);
		for (int j = 0; j < width; j++)
		{
			double	r = (double)j / width;
			double	g = (double)i / height;
			double	b = 0.25;
			mlx_pixel_put(mlx, mlx_win, j, i, rgt_to_int(255.999 * r, 255.999 * g, 255.999 * b));
		}
	}
	fprintf(stdout, "\n");
	mlx_loop(mlx);
	return (0);
}
