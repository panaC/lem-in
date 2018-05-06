/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 00:11:20 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 02:31:15 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include "libft.h"
#include "move.h"

t_bool		move_ants_node(t_env *e, size_t idx, t_room *from, t_room *to)
{
	if (from->id == e->room_start->id && from->nb_ant)
	{
		/*
		 * distribution
		 */
		printf("node : start nb %d\n", from->nb_ant);
		if (!move_tab_path_node_is_empty(e) && tab_path_node[idx])
		{
			tab_path_node[idx]--;
			from->nb_ant--;
			to->id_ant = e->nb_ants_moving;
			move_print(e->nb_ants_moving, to->name);
			++nb_ants_moving;
		}
		else if (move_tab_path_node_is_empty(e) && idx = 0)
		{
			from->nb_ant--;
			to->id_ant = e->nb_ants_moving;
			move_print(e->nb_ants_moving, to->name);
			++nb_ants_moving;
		}
	}
	else
	{
		printf("node : move 1 coup\n");
		if (from->id_ant)
		{
			move_print(from->id_ant, to->name);
			if (to->id == e->room_end->id)
				to->nb_ant++;
			else
				to->id_ant = from->id_ant;
			from->id_ant = 0;
		}
	}
	return (TRUE);
}

void		move_print(t_uint32 id, t_string name)
{
	ft_printf("L%d-%s", id, name);
}

void		move_init(t_env *e)
{
	t_uint32	nb;
	size_t		i;

	e->tab_path_node_size = 0;
	i = 0;
	while (i < e->tab_path_size)
	{
		e->tab_path_node_size += ft_lstlen(e->tab_path[i]);
		++i;
	}
	i = 0;
	while (i < e->tab_path_size)
	{
		e->tab_path_node[i] = e->tab_path_node_size / ft_lstlen(e->tab_path[i]);
		++i;
	}
}

void		move_while(t_env *e)
{
	t_uint32	it[e->tab_path_size];
	size_t		i;
	
	move_init(e);
	i = 0;
	while (i < e->tab_path_size)
	{
		it[i] = 0;
		++i;
	}
	i = 0;
	while (e->room_end->nb_ant < e->nb_ant_start)
	{
		printf("while : ants %d i %d\n", e->room_end->nb_ant, i);
		if (i >= e->tab_path_size)
			i = 0;
		move_iter(e->tab_path[i], &(it[i]));
		++i;
	}
}

void		move_iter(t_env *e, t_list *l, t_uint32 *it, size_t i)
{
	t_uint32		i;
	t_room			*to;
	const size_t	len = ft_lstlen(l);

	i = 0;
	if (*it >= len)
		*it = 0;
	to = e->room_end;
	printf("iter : it %d i %d\n", it, i);
	while (l)
	{
		if (i == it)
		{
			printf("iter : i == it %d\n", it);
			move_ants_node(e, i, (t_room*)l->content, to);
		}
		to = (t_room*)l->content;
		l = l->next;
	}
	(*it)++;
}
