/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:14 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 14:58:59 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	add_obj(t_object **lst, t_object *new)
{
	t_object	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = last_obj(*lst);
	last->next = new;
}

void	*last_obj(t_object *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
