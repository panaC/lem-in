/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:10:53 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/02 16:10:28 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

t_bool			parser_room_is_valid(t_string l)
{
	t_string	**tab;

	tab = parser_room_get(l);
	if (tab)
	{
		ft_memdel((void*)tab[0]);
		ft_memdel((void*)tab[1]);
		free(tab);
		return (TRUE);
	}
	return (FALSE);
}

t_string		*parser_room_get(t_string l)
{
	t_string	**tab;

	if (ft_strnbchr(l , '-') == 1)
	{
		tab = ft_strsplit(l, '-');
		if (tab)
		{
			if (ft_lstfind(e->lst_room, (void*)tab[0], parser_cmp_name))
			{
				if (ft_lstfind(e->lst_room, (void*)tab[1], parser_cmp_name))
					return (tab);
				else
				{
					printf("ERROR : Room right '%20s' is unknow\n", tab[1]);
				}
			}
			else
			{
				printf("ERROR : Room left '%20s' is unknow\n", tab[0]);
			}
		}
		else
		{
			printf("ERROR : Memory error\n");
		}
	}
	else
	{
		printf("ERROR : Syntax error pipe %d '-'\n", ft_strnbchr(l , '-'));
	}
	return (NULL);
}

t_bool			parser_room_set_mat(int i1, int i2)
{
	e->mat_adj[i1 / e->mat_size + i2 % e->mat_size] = '1';
	e->mat_adj[i2 / e->mat_size + i1 % e->mat_size] = '1';
	return (TRUE);
}
