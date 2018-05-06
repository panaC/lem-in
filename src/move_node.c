/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 07:57:50 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:00:50 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "move.h"

void		move_ants_node(t_env *e, size_t idx, t_room *from, t_room *to)
{
	if (from->id == e->room_start->id && from->nb_ant)
	{
		move_ants_node_start(e, idx, from, to);
	}
	else if (from->id_ant)
	{
		move_print(from->id_ant, to->name, FALSE);
		if (to->id == e->room_end->id)
			to->nb_ant++;
		else
			to->id_ant = from->id_ant;
		from->id_ant = 0;
	}
}

void		move_ants_node_start(t_env *e, size_t idx, t_room *from, t_room *to)
{
	if (to->id == e->room_end->id)
	{
		e->tab_path_node[idx]--;
		from->nb_ant--;
		to->nb_ant++;
		move_print(e->nb_ants_moving, to->name, FALSE);
		e->nb_ants_moving++;
	}
	else if (!move_tab_path_node_is_empty(e) && e->tab_path_node[idx])
	{
		e->tab_path_node[idx]--;
		from->nb_ant--;
		to->id_ant = e->nb_ants_moving;
		move_print(e->nb_ants_moving, to->name, FALSE);
		e->nb_ants_moving++;
	}
	else if (move_tab_path_node_is_empty(e) && idx == 0)
	{
		from->nb_ant--;
		to->id_ant = e->nb_ants_moving;
		move_print(e->nb_ants_moving, to->name, FALSE);
		e->nb_ants_moving++;
	}
}
