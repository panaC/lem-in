/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:08:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:45:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "parser.h"
#include "lemin.h"
#include "room.h"

int		parser(t_env *e, t_string l)
{
	static int		i = START_CODE;

	if (parser_is_comment(l) || parser_is_command(l))
		return (i);
	if (i == START_CODE)
		i = parser_nb_ant(e, l);
	else if (i == ROOM_CODE)
		i = parser_room(e, l);
	else if (i == PIPE_CODE)
		i = parser_pipe(e, l);
	if (i != ERROR_CODE)
	{
		ft_putstr(l);
		ft_putchar('\n');
	}
	return (i);
}

int		parser_nb_ant(t_env *e, t_string l)
{
	if (l && *l && ft_strlen(l) > 0 &&
			ft_strlennb(l) > 0 && ft_strlennb(l) < 10)
	{
		if (ft_atoi(l) > 0)
		{
			e->nb_ant_start = ft_atoi(l);
			return (ROOM_CODE);
		}
		else
		{
			ft_sprintf(&e->str_err, "Wrong numbers %d\n", ft_atoi(l));
		}
	}
	else
	{
		ft_sprintf(&e->str_err, "Wrong ants numbers (%d digit)\n",
				ft_strlennb(l));
	}
	return (ERROR_CODE);
}

int		parser_room(t_env *e, t_string l)
{
	static t_e_type		i = EMPTY;
	t_string			ss;

	ss = NULL;
	if (l && parser_room_is_valid(e, l))
		return (parser_pipe(e, l));
	if (ft_strequ(l, COM_START) && i == EMPTY)
		i = START;
	else if (ft_strequ(l, COM_END) && i == EMPTY)
		i = END;
	else if (l && *l && ft_strlen(l) >= 5 && l[0] != 'L')
	{
		if (ft_strnbchr(l, ' ') == 2)
		{
			if (parser_room_line(e, l, &i, &ss))
				return (ROOM_CODE);
		}
		else
			ft_sprintf(&e->str_err, "Wrong line %d ' '\n", ft_strnbchr(l, ' '));
	}
	else
		ft_sprintf(&e->str_err, "Line error (%ld char) %s\n", ft_strlen(l),
				l[0] == 'L' ? " -> 'L' forbidden" : "");
	ft_strdel(&ss);
	return ((e->str_err == NULL) ? ROOM_CODE : ERROR_CODE);
}

int		parser_pipe(t_env *e, t_string l)
{
	static int			i = 0;
	t_string			*tab;
	t_room				*a;
	t_room				*b;

	if (i == 0 && parser_pipe_init(e) > EMPTY_CODE)
		return (ERROR_CODE);
	i++;
	if (parser_room_is_valid(e, l))
	{
		tab = parser_room_get(e, l);
		a = ((t_room*)ft_lstfind(e->lst_room, (void*)tab[0], room_cmp_name));
		b = ((t_room*)ft_lstfind(e->lst_room, (void*)tab[1], room_cmp_name));
		room_set_mat(e, a->id, b->id);
		ft_strdel(&(tab[0]));
		ft_strdel(&(tab[1]));
		free(tab);
		return (PIPE_CODE);
	}
	else
	{
		parser_room_get_err(e, l);
	}
	return (ERROR_CODE);
}
