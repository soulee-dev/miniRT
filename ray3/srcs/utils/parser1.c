/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:06:56 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 18:07:22 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

size_t	count_strings(char **strs)
{
	int	count;

	count = 0;
	while (strs[count])
		count ++;
	return (count);
}

void	free_strs(char ***strs)
{
	int	i;

	i = 0;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
	*strs = 0;
}

char	*make_code(const char *set)
{
	static char	code[CODE_SIZE];

	ft_bzero(code, CODE_SIZE);
	while (*set)
		code[(int)*set++] = 1;
	return (code);
}

char	**ft_split2(char const *s, const char *set)
{
	char	*code;
	char	*buf[10000];
	int		len;
	int		l;
	int		r;

	code = make_code(set);
	len = 0;
	l = 0;
	r = -1;
	while (s[++r])
	{
		if (code[(int)s[r]])
		{
			if (l < r)
				buf[len++] = ft_strndup(s + l, r - l);
			l = r + 1;
		}
	}
	if (l < r)
		buf[len++] = ft_strndup(s + l, r - l);
	buf[len++] = 0;
	return (ft_memcpy(malloc(sizeof(char *) * len), buf, sizeof(char *) * len));
}
