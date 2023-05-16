/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:55:38 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 19:05:55 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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