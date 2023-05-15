/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:33:23 by soulee            #+#    #+#             */
/*   Updated: 2023/05/15 16:59:28 by soulee           ###   ########.fr       */
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
	size_t	i;
	size_t	len;
	char	**strs;

	strs = ft_split(line, ' ');
	len = count_strings(strs);
	if (count_strings(strs) == 0)
		exit_error("error: Invalid file format");
	i = 0;
	while (i < len)
	{
		printf("%s ", strs[i]);
	}
	printf("\n");
	free_strs(&strs);
}

void	read_file(char *file_name)
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
