/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 00:11:20 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 07:58:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "move.h"

void		move_print(t_uint32 id, t_string name, t_bool st)
{
	static t_bool	state = TRUE;

	if (st)
	{
		state = TRUE;
		ft_putchar('\n');
		return ;
	}
	if (!state)
		ft_putchar(' ');
	state = FALSE;
	ft_printf("L%d-%s", id, name);
}

void		move_init(t_env *e)
{
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
	size_t		i;
	t_room		*to;
	t_list		*l;
	
	move_init(e);
	i = 0;
	while (e->room_end->nb_ant < e->nb_ant_start)
	{
		while (i < e->tab_path_size)
		{
			to = e->room_end;
			l = e->tab_path[i];
			while (l)
			{
				move_ants_node(e, i, (t_room*)l->content, to);
				to = (t_room*)l->content;
				l = l->next;
			}
			i++;
		}
		move_print(0, NULL, TRUE);
		i = 0;
	}
}

t_bool		move_tab_path_node_is_empty(t_env *e)
{
	size_t		i;
	int			son;

	i = 0;
	son = 0;
	while (i < e->tab_path_size)
	{
		son += e->tab_path_node[i];
		++i;
	}
	if (e->tab_path_size && son == 0)
		return (TRUE);
	return (FALSE);
}
