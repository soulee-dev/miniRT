/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:59:53 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 15:04:17 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

t_object	*object(int type, void *element)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	// Exit error when malloc failed;
	if (!new)
		;
	new->type = type;
	new->element = element;
	new->next = NULL;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	// Exit error when malloc failed;
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		;
	sp->center = center;
	sp->radius = radius;
	return (sp);
}
