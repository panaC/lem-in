/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:10:53 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 16:57:58 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <stdlib.h>
#include "lemin.h"
#include "parser.h"

t_bool			parser_room_is_valid(t_list *lst, t_string l)
{
	t_string	*tab;

	tab = NULL;
	tab = parser_room_get(lst, l);
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

t_string		*parser_room_get(t_list *lst, t_string l)
{
	t_string	*tab;

	if (ft_strnbchr(l , '-') == 1)
	{
		tab = ft_strsplit(l, '-');
		if (tab)
		{
			if (ft_lstfind(lst, (void*)tab[0], parser_cmp_name))
			{
				if (ft_lstfind(lst, (void*)tab[1], parser_cmp_name))
					return (tab);
				else
				{
					//printf("ERROR : Room right '%20s' is unknow\n", tab[1]);
				}
			}
			else
			{
				//printf("ERROR : Room left '%20s' is unknow\n", tab[0]);
			}
		}
		else
		{
			//printf("ERROR : Memory error\n");
		}
	}
	else
	{
		//printf("ERROR : Syntax error pipe %d '-'\n", ft_strnbchr(l , '-'));
	}
	return (NULL);
}

t_bool			parser_room_set_mat(t_env *e, int i1, int i2)
{
	printf("ID1 %d ID2 %d\n", i1, i2);
	e->mat_adj[i1 * e->mat_size + i2] = '1';
	e->mat_adj[i2 * e->mat_size + i1] = '1';
	return (TRUE);
}

t_string		parser_room_get_name(t_env *e, int id)
{
	t_room		*ret;
	
	ret = (t_room*)ft_lstfind(e->lst_room, (void*)&id, parser_cmp_id);
	if (ret)
		return (ret->name);
	return (NULL);
}
