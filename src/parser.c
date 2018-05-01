/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:08:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 15:12:06 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "parser.h"

int		parser(t_env *e, t_string l)
{
	static int		i = 0;

	ft_putstr(l);
	if (parser_is_comment(l))
		return (i);
	if (i == 0)
		i = parser_nb_ant(e, l);
	else if (i == 1)
		i = parser_room(e, l);
	else if (i == 2)
		i = parser_pipe(e, l);
	return (i);
}

int		parser_nb_ant(t_env *e, t_string l)
{
	if (l && *l && ft_strlen(l) > 0 &&
			ft_strlennb(l) > 0 && ft_strlennb(l) < 10)
		return (1);
	return (0);
}

int		parser_room(t_env *e, t_string l)
{
	static e_type	i = EMPTY;
	int				nb[2];
	t_string		ss;

	if (l && *l && ft_strlen(l) >= 5 && ft_strnbchr(l , ' ') == 2 &&
			ft_strnbchr(l, '-') == 0)
	{
		ss = ft_strsub(l, 0, ft_strchr(l, ' ') - l);
		if (ft_lststrfind(e->lst_room, NULL, ss))
			ft_lstaddstr(&e->lst_room, ss);
		else
			return (0);
		l = ft_strchr(l, ' ') + 1;
		nb[0] = ft_strnlennb(l, ft_strchr(l, ' ') - l);
		l = ft_strchr(l, ' ') + 1;
		nb[1] = ft_strlennb(l);
		if (nb[0] > 0 && nb[0] < 10 && nb[1] > 0 && nb[1] < 10)
			return (1);
	}
	else if (ft_strequ(l, COM_START))
		i = START;
	else if (ft_strequ(l, COM_END))
		i = END;
	else if (ft_strnbchr(l, '-') == 1)
	{
		parser_pipe(e, l);
	}
	return (0);
}

int		parser_pipe(t_env *e, t_string l)
{
	static int			i = 0;

	if (i == 0)
	{
		l = ft_strchr(l, ' ');
		e->piece_y = ft_atoi(l);
		e->piece_x = ft_atoi((l == NULL ? NULL : ft_strchr(l + 1, ' ')));
		if ((e->piece_x == 0 || e->piece_y == 0))
			return (0);
		ft_bzero(e->piece_offset, NB_PIECE_OFFSET);
		e->piece_pixel_bool = FALSE;
		e->piece_offset_size = 0;
	}
	else if (ft_strchr(l, '*') != NULL)
		e->piece_offset_size = parser_piece_shape(e, l, e->piece_offset_size);
	else
		e->piece_offset[e->piece_offset_size] += OFFSET_JUMP;
	if (i == e->piece_y)
	{
		i = 0;
		return (3);
	}
	++i;
	return (2);
}
