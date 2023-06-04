/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:43:49 by soulee            #+#    #+#             */
/*   Updated: 2023/05/15 14:08:26 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	if (!s)
		return (0);
	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (*s == chr)
		return ((char *)s);
	return (0);
}

char	*ft_extract_line(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_strndup(s, i + 1));
}

char	*ft_mem_clear(char **mem, char *buffer)
{
	free(*mem);
	free(buffer);
	*mem = 0;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		read_size;
	static char	*text_buffer[OPEN_MAX];
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
		return (ft_mem_clear(&text_buffer[fd], buffer));
	while (read_size > 0)
	{
		buffer[read_size] = 0;
		text_buffer[fd] = ft_strjoin(text_buffer[fd], buffer);
		if (!text_buffer[fd] || ft_strchr(text_buffer[fd], '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	line = ft_extract_line(text_buffer[fd]);
	text_buffer[fd] = ft_remain_text(text_buffer[fd]);
	return (line);
}
