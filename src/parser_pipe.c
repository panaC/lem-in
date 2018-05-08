/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:36:44 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/08 14:24:06 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"

t_string		*parser_room_get(t_env *e, t_string l)
{
	t_string	*tab;

	if (ft_strnbchr(l, '-') == 1)
	{
		tab = ft_strsplit(l, '-');
		if (tab && tab[0] && tab[1] && !ft_strequ(tab[0], tab[1]))
		{
			if (ft_lstfind(e->lst_room, (void*)tab[0], room_cmp_name))
			{
				if (ft_lstfind(e->lst_room, (void*)tab[1], room_cmp_name))
					return (tab);
			}
		}
		del_room_tab_err(tab);
	}
	return (NULL);
}

t_string		*parser_room_get_err(t_env *e, t_string l)
{
	t_string	*tab;

	if (ft_strnbchr(l, '-') == 1)
	{
		tab = ft_strsplit(l, '-');
		if (tab && tab[0] && tab[1] && !ft_strequ(tab[0], tab[1]))
		{
			if (ft_lstfind(e->lst_room, (void*)tab[0], room_cmp_name))
			{
				if (!ft_lstfind(e->lst_room, (void*)tab[1], room_cmp_name))
					ft_sprintf(&e->str_err, "Room right %.20s is unknow\n",
							tab[1]);
			}
			else
				ft_sprintf(&e->str_err, "Room left %.20s is unknow\n", tab[0]);
		}
		else
			ft_sprintf(&e->str_err, "Pipe error\n");
		del_room_tab_err(tab);
	}
	else
		ft_sprintf(&e->str_err, "Syntax error pipe %d '-'\n",
				ft_strnbchr(l, '-'));
	return (NULL);
}

t_bool			parser_room_is_valid(t_env *e, t_string l)
{
	t_string	*tab;

	tab = NULL;
	tab = parser_room_get(e, l);
	if (tab)
	{
		ft_strdel(&(tab[0]));
		ft_strdel(&(tab[1]));
		free(tab);
		return (TRUE);
	}
	return (FALSE);
}

int				parser_pipe_init(t_env *e)
{
	e->mat_size = ft_lstlen(e->lst_room);
	e->mat_adj = (t_string)ft_memalloc(e->mat_size * e->mat_size + 1);
	if (e->mat_adj)
		ft_memset(e->mat_adj, '0', e->mat_size * e->mat_size);
	else
	{
		ft_sprintf(&e->str_err, "Memory error\n");
		return (ERROR_CODE);
	}
	return (EMPTY_CODE);
}
