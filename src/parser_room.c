/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:10:53 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 07:39:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"

t_bool			parser_room_loc(t_string l, t_point *loc)
{
	int			nb[2];

	l = ft_strchr(l, ' ') + 1;
	nb[0] = ft_strnlennb(l, ft_strchr(l, ' ') - l);
	loc->x = ft_atoi(l);
	l = ft_strchr(l, ' ') + 1;
	nb[1] = ft_strlennb(l);
	loc->y = ft_atoi(l);
	if (nb[0] > 0 && nb[0] < 10 && nb[1] > 0 && nb[1] < 10)
		return (TRUE);
	return (FALSE);
}

t_bool			parser_room_set_list(t_env *e, t_string ss, t_point loc,
		t_e_type *i)
{
	if (!ft_lstfind(e->lst_room, (void*)&loc, room_cmp_loc))
	{
		if (*i == START)
			e->room_start = room_add_lst(&(e->lst_room),
					ss, loc, START);
		else if (*i == END)
			e->room_end = room_add_lst(&(e->lst_room),
					ss, loc, END);
		else
			room_add_lst(&(e->lst_room), ss, loc, NODE);
		*i = EMPTY;
		return (TRUE);
	}
	return (FALSE);
}

t_bool			parser_room_line(t_env *e, t_string l, t_e_type *i,
		t_string *ss)
{
	t_point		loc;

	*ss = ft_strsub(l, 0, ft_strchr(l, ' ') - l);
	if (ft_strchr(*ss, '-') == 0)
	{
		if (!ft_lstfind(e->lst_room, (void*)(*ss), room_cmp_name))
		{
			if (parser_room_loc(l, &loc))
			{
				if (parser_room_set_list(e, *ss, loc, i))
					return (TRUE);
				else
					ft_sprintf(&e->str_err,
							"Room X %d, Y %d are already set\n", loc.x, loc.y);
			}
			else
				ft_sprintf(&e->str_err, "Syntax error : wrong X or Y\n");
		}
		else
			ft_sprintf(&e->str_err, "Room %.20s is already set\n", *ss);
	}
	else
		ft_sprintf(&e->str_err, "Room name %.20s is wrong\n", ss);
	return (FALSE);
}
