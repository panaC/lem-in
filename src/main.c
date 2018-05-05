/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:32:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 02:29:34 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <get_next_line.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"

int		main(void)
{
	t_env		e;
	t_uint8		res;
	t_string	line;

	init(&e);
	while (1)
	{
		if (get_next_line(STDIN_FILENO, &line) > 0)
		{
			res = parser(&e, line);
			ft_memdel((void**)&line);
			if (res == 0)
				break;
		}
		else
			break;
	}
	ft_memdel((void**)&line);
	t_list *j = e.lst_room;
	t_room *a = NULL;
	while (j)
	{
		a = (t_room*)j->content;
		if (a)
			printf("id %d name %s x %d y %d\n", a->id, a->name, a->loc.x, a->loc.y);
		j = j->next;

	}

	printf("MATRICE :%ld:%ld: \n%s\n", e.mat_size, ft_strlen(e.mat_adj), e.mat_adj);

	if (e.room_start && e.room_end)
	{
		e.room_start->nb_ant = e.nb_ant_start;
		/*ok*/
		size_t i = 0;
		while (i < ft_strlen(e.mat_adj))
		{
			if (e.mat_adj[i] == '1')
			{
				printf("id %ld id %ld\n",  i / e.mat_size, i % e.mat_size);
				printf("%s-%s\n", room_get_name(&e, i / e.mat_size),
						room_get_name(&e, i % e.mat_size));
			}
			i++;
		}
	}
	else
	{
		printf("ERROR : Room Start or End are not set\n");
	}
	ft_printf("ERROR : %s\n", e.str_err);
	return (0);
}
