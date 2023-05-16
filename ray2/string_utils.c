/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:55:38 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 16:56:58 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_stoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	if ((*str == '-' || *str == '+') && *str++ == '-')
		sign = -1;
	res = 0;
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (res * sign);
}

double  ft_stof(const char *str)
{
	int     sign;
	char	**strs;
	double	res;

	sign = 1;
	if ((*str == '-' || *str == '+') && *str++ == '-')
		sign = -1;
	strs = ft_split(str, '.');
	res = ft_stoi(strs[0]);
	if (strs[1])
		res += (ft_stoi(strs[1]) / ft_pow(10, ft_strlen(strs[1])));
	ft_delete_split(strs);
	return (res * sign);
}
