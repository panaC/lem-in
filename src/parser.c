/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:08:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 19:00:00 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "parser.h"

int		parser(t_env *e, t_string l)
{
	static int		i = 0;

	ft_putstr(l);
	if (parser_is_comment(l) ||
			(!ft_strequ(l, COM_START) && !ft_strequ(l, COM_END)))
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
	printf("ERROR : Le nombre de fourmi est incorrect (%d digit)\n",
			ft_strlennb(l));
	return (0);
}

int		parser_room(t_env *e, t_string l)
{
	static e_type	i = EMPTY;
	t_point			loc;
	t_string		ss;

	if (l && ft_strequ(l, COM_START) && i == EMPTY)
		i = START;
	else if (l && ft_strequ(l, COM_END) && i == EMPTY)
		i = END;
	else if (l && /*pipe valide*/)
				/*
				 * TESTER SI ROOM DROITE EST VALIDE ET '-' ET ROOM GAUCHE VALIDE
				 * 		ALORS PASSER A L'ETAPE 2
				 */
		parser_pipe(e, l);
	else if (l && *l && ft_strlen(l) >= 5 && l[0] != 'L')
	{
		if (ft_strnbchr(l , ' ') == 2 && ft_strnbchr(l, '-') == 0)
		{
			ss = ft_strsub(l, 0, ft_strchr(l, ' ') - l);
			if (!ft_lstfind(e->lst_room, (void*)ss, parser_cmp_name))
			{
				l = ft_strchr(l, ' ') + 1;
				loc.x = ft_strnlennb(l, ft_strchr(l, ' ') - l);
				l = ft_strchr(l, ' ') + 1;
				loc.y = ft_strlennb(l);
				if (loc.x > 0 && loc.x < 10 && loc.y > 0 && loc.y < 10)
				{
					if (!ft_lstfind(e->lst_room, (void*)loc, parser_cmp_loc))
					{
						if (i == START)
						{
							/* ADD the Room start*/
							i = EMPTY;
							init_room(&(e->room_start), 0, ss, START);
							e->room_start.loc = loc;
						}
						else if (i == END)
						{
							/* ADD the Room end*/
							i = EMPTY;
							init_room(&(e->room_end), 1, ss, END);
							e->room_end.loc = loc;
						}
						else
						{
							/* ADD the Room dans la liste chainee */
							room_add_lst(&(e->lst_room), ss, loc);
						}
						ft_memdel((void**)ss);
						return (1);
					}
					else
					{
						printf("ERROR : Room X %d, Y %d is already set\n",
								nb[0], nb[1]);
					}
				}
				else
				{
					printf("ERROR : Syntax error : X -> %d digit, Y -> %d digit\n",
							nb[0], nb[1]);
				}
			}
			else
			{
				printf("ERROR : Room '%20s' is already set\n", ss);
			}
		}
		else
		{
			printf("ERROR : Syntax error : %d ' ' et %d '-'\n",
					ft_strnbchr(l , ' '), ft_strnbchr(l, '-'));
		}
	}
	else
	{
		printf("ERROR : lign error (%d char) %s\n", ft_strlen(l),
				l[0] == 'L' ? " -> 'L' forbidden" : "");
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
