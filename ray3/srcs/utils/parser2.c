/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:07:37 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 18:08:35 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

void	check_valid(double val, double min, double max)
{
	if (!(val >= min && val <= max))
		exit_error("error: Value not in range");
}

void	check_valid_vec3(t_vec3 vec3, double min, double max)
{
	check_valid(vec3.x, min, max);
	check_valid(vec3.y, min, max);
	check_valid(vec3.z, min, max);
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

void	exit_error(char *s)
{
	while (*s)
		write(2, s++, 1);
	write(2, "\n", 1);
	exit(1);
}
