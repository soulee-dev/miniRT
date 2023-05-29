/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:37:16 by soulee            #+#    #+#             */
/*   Updated: 2023/05/29 17:04:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

void	parse_line(t_scene *scene, char *line)
{
	size_t	len;
	char	**strs;

	strs = ft_split2(line, " \t\n\v\f\r,");
	len = count_strings(strs);
	if (len == 0)
		exit_error("error: Invalid file format");
	if (!ft_strncmp(strs[0], "A", 1))
		add_ambient_light(scene, strs);
	else if (!ft_strncmp(strs[0], "C", 1))
		add_camera(scene, strs);
	else if (!ft_strncmp(strs[0], "L", 1))
		add_light(scene, strs);
	else if (!ft_strncmp(strs[0], "sp", 2))
		add_sphere(scene, strs);
	else if (!ft_strncmp(strs[0], "pl", 2))
		add_plane(scene, strs);
	else if (!ft_strncmp(strs[0], "cy", 2))
		add_cylinder(scene, strs);
	else if (!ft_strncmp(strs[0], "#", 1))
		;
	else
		exit_error("error: Invalid format");
	free_strs(&strs);
}

void	read_file(t_scene *scene, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error("error: File open failed");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (line[0] != '\0')
			parse_line(scene, line);
		free(line);
	}
}
