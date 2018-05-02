/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:59:46 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/02 17:33:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

int			init(t_env *e)
{
	e->lst_room = NULL;
	e->mat_adj = NULL;
	return (TRUE);
}

void		init_room(t_room *r, t_uint32 id, t_string s, t_e_type type)
{
	if (!r)
		return ;
	r->id = id;
	r->name = s;
	r->id_ant = 0;
	r->nb_ant = 0;
	r->type = type;
}

t_room		room_create(t_uint32 id, t_string s, t_e_type type, t_point loc)
{
	t_room	a;

	init_room(&a, id, s, type);
	a.loc.x = loc.x;
	a.loc.y = loc.y;
	return (a);
}

void		room_add_lst(t_list **l, t_string s, t_point loc)
{
	t_room	a;

	a = room_create(ft_lstlen(*l), s, NODE, loc);
	ft_lstadd(l, ft_lstnew(&a, sizeof(a)));
}
