/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 08:07:56 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:40:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"
#include "algo.h"

void			bfs_recurs(t_env *e, int id, t_list **prev, t_list **actl)
{
	t_uint32	i;
	const int	pos = id * e->mat_size;

	i = pos;
	while (i < pos + e->mat_size)
	{
		if (e->mat_adj[i] == '1')
		{
			id = i % e->mat_size;
			if (id == NODE_END->id)
			{
				bfs_recurs_end(prev, actl);
				return ;
			}
			else if (!path_tab_node_id_is_used(e, id))
			{
				bfs_recurs_search(e, id, prev, actl);
			}
		}
		++i;
	}
}

void			bfs_recurs_end(t_list **prev, t_list **actl)
{
	if (*prev == NULL || ft_lstlen(*actl) < ft_lstlen(*prev))
	{
		if (*prev)
			ft_lstdel(prev, del_lst_node_empty);
		*prev = NULL;
		ft_lstcpy(*actl, prev);
	}
}

void			bfs_recurs_search(t_env *e, int id, t_list **prev,
		t_list **actl)
{
	t_room		*a;

	a = (t_room*)ft_lstfind(*actl, (void*)&id, room_cmp_id);
	if (!a)
	{
		a = (t_room*)ft_lstfind(e->lst_room, (void*)&id, room_cmp_id);
		if (a)
		{
			room_push_lst(actl, a);
			bfs_recurs(e, id, prev, actl);
			ft_lstpull(actl);
		}
	}
}
