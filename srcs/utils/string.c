/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:06:56 by soulee            #+#    #+#             */
/*   Updated: 2023/05/25 22:11:13 by soulee           ###   ########.fr       */
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

double	ft_atof(const char *str)
{
	int		sign;
	char	**strs;
	double	res;

	sign = 1;
	if ((*str == '-' || *str == '+') && *str++ == '-')
		sign = -1;
	strs = ft_split(str, '.');
	res = ft_atoi(strs[0]);
	if (strs[1])
		res += (ft_atoi(strs[1]) / pow(10, ft_strlen(strs[1])));
	free_strs(&strs);
	return (res * sign);
}
