/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:59:46 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/03 16:46:48 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

int			init(t_env *e)
{
	e->lst_room = NULL;
	e->mat_adj = NULL;
	e->room_start = NULL;
	e->room_end = NULL;
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

t_room		*room_create(t_uint32 id, t_string s, t_e_type type, t_point loc)
{
	t_room	*a;

	a = NULL;
	a = (t_room*)ft_memalloc(sizeof(*a));
	if (a)
	{
		init_room(a, id, s, type);
		a->loc.x = loc.x;
		a->loc.y = loc.y;
	}
	return (a);
}

t_room		*room_add_lst(t_list **l, t_string s, t_point loc, t_e_type type)
{
	t_room	*a;
	t_list	*n;

	a = room_create(ft_lstlen(*l), s, type, loc);
	if (a)
	{
		n = (t_list*)ft_memalloc(sizeof(*n));
		if (n)
		{
			n->next = NULL;
			n->content = (void*)a;
			n->content_size = sizeof(*a);
			ft_lstadd(l, n);
		}
	}
	return (a);
}
