/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 06:36:39 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:47:42 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <get_next_line.h>
#include "parser.h"
#include "lemin.h"
#include "room.h"
#include "algo.h"
#include "move.h"

void		parser_get_map(t_env *e)
{
	t_string	line;
	t_uint8		res;

	while (1)
	{
		if (get_next_line(STDIN_FILENO, &line) > 0)
		{
			res = parser(e, line);
			ft_memdel((void**)&line);
			if (res == 0)
				break ;
		}
		else
			break ;
	}
	ft_memdel((void**)&line);
}

void		parser_algo(t_env *e)
{
	if (e->room_start && e->room_end)
	{
		e->room_start->nb_ant = e->nb_ant_start;
		if (algo_pathfinder(e))
		{
			ft_putchar('\n');
			parser_verbose(e);
			move_while(e);
		}
		else
		{
			if (e->str_err)
				ft_printf("ERROR : %s", e->str_err);
			else
				ft_putstr("ERROR : No path found\n");
		}
	}
	else
	{
		if (e->str_err)
			ft_printf("ERROR : %s", e->str_err);
		else
			ft_putstr("ERROR : Room Start or End not set\n");
	}
}

void		parser_verbose(t_env *e)
{
	size_t		i;
	t_room		*a;
	int			n;
	t_list		*j;

	i = 0;
	n = 0;
	if (e->verbose)
	{
		ft_printf("VERBOSE : %u path find\n", e->tab_path_size);
		while (i < e->tab_path_size)
		{
			ft_printf("VERBOSE : path numero %ld\n", i);
			j = e->tab_path[i];
			n = 0;
			while (j)
			{
				if ((a = (t_room*)j->content))
					ft_printf("VERBOSE : %d -> id %d name %s x %d y %d\n",
							n++, a->id, a->name, a->loc.x, a->loc.y);
				j = j->next;
			}
			++i;
		}
	}
}
