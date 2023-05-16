/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:33:23 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 16:42:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	parse_line(char *line)
{
	// size_t	i;
	size_t	len;
	char	**strs;

	strs = ft_split2(line, " \t\n\v\f\r");
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

void	read_file(t_env *env, char *file_name)
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
			parse_line(line);
		free(line);
	}
}
