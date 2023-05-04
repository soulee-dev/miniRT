/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:15:49 by soulee            #+#    #+#             */
/*   Updated: 2023/05/04 16:43:15 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color	checker_value(t_checker checker, double u, double v, t_point3 *p)
{
	double	sines;

	(void) u;
	(void) v;
	sines = sin(10 * p->x) * sin(10 * p->y) * sin (10 * p->z);
	if (sines < 0)
		return (checker.odd);
	else
		return (checker.even);
}
