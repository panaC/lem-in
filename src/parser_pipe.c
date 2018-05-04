/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:36:44 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 23:15:46 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"

t_string		*parser_room_get(t_env *e, t_string l)
{
	t_string	*tab;

	if (ft_strnbchr(l , '-') == 1)
	{
		tab = ft_strsplit(l, '-');
		if (tab)
		{
			if (ft_lstfind(e->lst_room, (void*)tab[0], room_cmp_name))
			{
				if (ft_lstfind(e->lst_room, (void*)tab[1], room_cmp_name))
					return (tab);
			}
		}
	}
	return (NULL);
}

t_string		*parser_room_get_err(t_env *e, t_string l)
{
	t_string	*tab;

	if (ft_strnbchr(l , '-') == 1)
	{
		tab = ft_strsplit(l, '-');
		if (tab)
		{
			if (ft_lstfind(e->lst_room, (void*)tab[0], room_cmp_name))
			{
				if (ft_lstfind(e->lst_room, (void*)tab[1], room_cmp_name))
					return (NULL);
				else
					ft_sprintf(&e->str_err, "Room right %.20s is unknow\n",
							tab[1]);
			}
			else
				ft_sprintf(&e->str_err, "Room left %.20s is unknow\n", tab[0]);
		}
		else
			ft_sprintf(&e->str_err, "Memory error\n");
	}
	else
		ft_sprintf(&e->str_err, "Syntax error pipe %d '-'\n",
				ft_strnbchr(l , '-'));
	return (NULL);
}

t_bool			parser_room_is_valid(t_env *e, t_string l)
{
	t_string	*tab;

	tab = NULL;
	tab = parser_room_get(e, l);
	if (tab)
	{
		//Abort
		//printf("FREE\n");
		//ft_memdel((void*)tab[0]);
		//ft_memdel((void*)tab[1]);
		//free(tab);
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
