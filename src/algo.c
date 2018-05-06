/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 02:27:35 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:23:39 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"
#include "algo.h"

t_bool			algo_pathfinder(t_env *e)
{
	t_list		*previous;
	t_list		*actual;

	previous = NULL;
	actual = NULL;
	while (TRUE)
	{
		room_push_lst(&actual, NODE_START);
		bfs_recurs(e, NODE_START->id, &previous, &actual);
		if (previous && !path_tab_check_size_one(e))
		{
			if (algo_pathfinder_set(e, &previous, &actual))
				return (TRUE);
		}
		else
		{
			if (algo_pathfinder_empty(e, &previous, &actual))
				return (TRUE);
			return (FALSE);
		}
	}
	return (FALSE);
}

t_bool		algo_pathfinder_set(t_env *e, t_list **previous, t_list **actual)
{
	if (e->tab_path_size > NB_PATH)
		return (TRUE);
	e->tab_path[e->tab_path_size] = NULL;
	ft_lstcpy(*previous, &(e->tab_path[e->tab_path_size]));
	++e->tab_path_size;
	if (*previous)
		ft_lstdel(previous, del_lst_node_empty);
	if (*actual)
		ft_lstdel(actual, del_lst_node_empty);
	*previous = NULL;
	*actual = NULL;
	return (FALSE);
}

t_bool		algo_pathfinder_empty(t_env *e, t_list **previous, t_list **actual)
{
	if (*previous)
		ft_lstdel(previous, del_lst_node_empty);
	if (*actual)
		ft_lstdel(actual, del_lst_node_empty);
	if (e->tab_path_size)
		return (TRUE);
	return (FALSE);
}
