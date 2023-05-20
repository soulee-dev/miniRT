/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:44:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/15 14:08:35 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	temp;

	i = 0;
	temp = ft_strlen(src);
	while (i < temp && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (temp);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*result_str;

	i = 0;
	result_str = malloc(sizeof(char) * (n + 1));
	if (!result_str)
		return (NULL);
	while (i < n)
	{
		result_str[i] = s1[i];
		i++;
	}
	result_str[i] = 0;
	return (result_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result_str)
	{
		free((void *)s1);
		return (NULL);
	}
	result_str[s1_len] = 0;
	ft_strlcpy(result_str, s1, s1_len + 1);
	free((void *)s1);
	ft_strlcpy(result_str + s1_len, (char *)s2, s2_len + 1);
	return (result_str);
}

char	*ft_remain_text(char *s)
{
	int		i;
	char	*result_str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	i++;
	result_str = ft_strndup(s + i, ft_strlen(s + i));
	free(s);
	return (result_str);
}
