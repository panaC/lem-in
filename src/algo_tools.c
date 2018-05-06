/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 02:45:56 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:40:30 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"

t_list		*get_list_under_node(t_env *e)
{
	t_list		*ret;
	int			id;
	t_uint32	i;

	ret = NULL;
	i = e->room_start->id * e->mat_size;
	while (i < e->room_start->id * e->mat_size + e->mat_size)
	{
		if (e->mat_adj[i] == '1')
		{
			id = i % e->mat_size;
			ft_lstadd(&(e->lst_room), ft_lstnew((void*)&id, sizeof(id)));
		}
		++i;
	}
	return (ret);
}

t_bool		path_tab_node_id_is_used(t_env *e, int id)
{
	size_t	i;

	i = 0;
	while (i < e->tab_path_size)
	{
		if (ft_lstfind(e->tab_path[i], (void*)&id, room_cmp_id))
			return (TRUE);
		++i;
	}
	return (FALSE);
}

t_bool		path_tab_check_size_one(t_env *e)
{
	size_t	i;

	i = 0;
	while (i < e->tab_path_size)
	{
		if (ft_lstlen(e->tab_path[i]) == 1)
			return (TRUE);
		++i;
	}
	return (FALSE);
}
