/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:37:16 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 18:39:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

void	parse_line(t_scene *scene, char *line)
{
	size_t	len;
	char	**strs;

	(void) scene;
	strs = ft_split2(line, " \t\n\v\f\r,");
	len = count_strings(strs);
	if (len == 0)
		exit_error("error: Invalid file format");
	if (!ft_strncmp(strs[0], "A", ft_strlen(strs[0])))
		printf("Ambient Light\n");
	else if (!ft_strncmp(strs[0], "C", ft_strlen(strs[0])))
		printf("Camera\n");
	else if (!ft_strncmp(strs[0], "L", ft_strlen(strs[0])))
		printf("Light\n");
	else if (!ft_strncmp(strs[0], "sp", ft_strlen(strs[0])))
		printf("Sphere\n");
	else if (!ft_strncmp(strs[0], "pl", ft_strlen(strs[0])))
		printf("Plane\n");
	else if (!ft_strncmp(strs[0], "cy", ft_strlen(strs[0])))
		printf("Cylinder\n");
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
		if (line[0] != '\0')
			parse_line(scene, line);
		free(line);
	}
}
