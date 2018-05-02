/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:08:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/02 19:11:28 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <stdlib.h>
#include "parser.h"
#include "lemin.h"
#define ERROR_CODE	0
#define START_CODE	1
#define ROOM_CODE	2
#define PIPE_CODE	3

int		parser(t_env *e, t_string l)
{
	static int		i = START_CODE;

	ft_putstr(l);
	ft_putchar('\n');
	if (parser_is_comment(l) ||
			(!(ft_strequ(l, COM_START) || ft_strequ(l, COM_END)) &&
			l[0] == '#' && l[1] && l[1] == '#'))
		return (i);
	if (i == START_CODE)
		i = parser_nb_ant(e, l);
	else if (i == ROOM_CODE)
		i = parser_room(e, l);
	else if (i == PIPE_CODE)
		i = parser_pipe(e, l);
	return (i);
}

int		parser_nb_ant(t_env *e, t_string l)
{
	if (l && *l && ft_strlen(l) > 0 &&
			ft_strlennb(l) > 0 && ft_strlennb(l) < 10)
	{
		if (ft_atoi(l) > 0)
		{
			e->room_start.nb_ant = ft_atoi(l);
			return (ROOM_CODE);
		}
		else
		{
			printf("ERROR : incorrect number %d\n", ft_atoi(l));
		}
	}
	else
	{
		printf("ERROR : Le nombre de fourmi est incorrect (%d digit)\n",
				ft_strlennb(l));
	}
	return (ERROR_CODE);
}

int		parser_room(t_env *e, t_string l)
{
	static t_e_type	i = EMPTY;
	t_point			loc;
	int				nb[2];
	t_string		ss;

	ss = NULL;
	if (l && ft_strequ(l, COM_START) && i == EMPTY)
		i = START;
	else if (l && ft_strequ(l, COM_END) && i == EMPTY)
		i = END;
	else if (l && parser_room_is_valid(e->lst_room, l))
		return (parser_pipe(e, l));
	else if (l && *l && ft_strlen(l) >= 5 && l[0] != 'L')
	{
		if (ft_strnbchr(l , ' ') == 2 && ft_strnbchr(l, '-') == 0)
		{
			ss = ft_strsub(l, 0, ft_strchr(l, ' ') - l);
			if (!ft_lstfind(e->lst_room, (void*)ss, parser_cmp_name))
			{
				l = ft_strchr(l, ' ') + 1;
				nb[0] = ft_strnlennb(l, ft_strchr(l, ' ') - l);
				loc.x = ft_atoi(l);
				l = ft_strchr(l, ' ') + 1;
				nb[1] = ft_strlennb(l);
				loc.y = ft_atoi(l);
				if (nb[0] > 0 && nb[0] < 10 && nb[1] > 0 && nb[1] < 10)
				{
					if (!ft_lstfind(e->lst_room, (void*)&loc, parser_cmp_loc))
					{
						if (i == START)
						{
							/* ADD the Room start*/
							i = EMPTY;
							init_room(&(e->room_start), -1, ss, START);
							e->room_start.loc = loc;
						}
						else if (i == END)
						{
							/* ADD the Room end*/
							i = EMPTY;
							init_room(&(e->room_end), -2, ss, END);
							e->room_end.loc = loc;
						}
						else
						{
							/* ADD the Room dans la liste chainee */
							room_add_lst(&(e->lst_room), ss, loc);
						}
						//abort
						//ft_memdel((void**)ss);
						return (ROOM_CODE);
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
		printf("ERROR : lign error (%ld char) %s\n", ft_strlen(l),
				l[0] == 'L' ? " -> 'L' forbidden" : "");
	}
	return (ERROR_CODE);
}

int		parser_pipe(t_env *e, t_string l)
{
	static int			i = 0;
	t_string			*tab;
	t_room *a = NULL;
	t_room *b = NULL;

	if (i == 0)
	{
		e->mat_size = ft_lstlen(e->lst_room);
		/*if (e->room_start.id == -1 && e->room_end.id == -2)
		{*/
			e->mat_adj = (t_string)ft_memalloc(e->mat_size * e->mat_size + 1);
			if (e->mat_adj)
				ft_memset(e->mat_adj, '0', e->mat_size * e->mat_size);
			else
			{
				printf("ERROR : Memory error\n");
				return (ERROR_CODE);
			}
		/*}
		else
		{
			printf("ERROR : Room Start or End has not set\n");
		}*//* Ne pas tester si room start,end set ici mais au debut de l'algo */
	}
	i++;
	if (parser_room_is_valid(e->lst_room, l))
	{
		tab = parser_room_get(e->lst_room, l);
		/* ici tester tab et is valid pour print error*/
		a = ((t_room*)ft_lstfind(e->lst_room, (void*)tab[0], parser_cmp_name));
		b = ((t_room*)ft_lstfind(e->lst_room, (void*)tab[1], parser_cmp_name));
		printf("a %p b %p\n", a, b);
		printf("a %d b %d\n", a->id, b->id);
		parser_room_set_mat(e, a->id, b->id);
		//Abort
		//ft_memdel((void*)tab[0]);
		//ft_memdel((void*)tab[1]);
		//free(tab);
		return (PIPE_CODE);
	}
	else
	{
		printf("ERROR : Syntax error pipe\n");
	}
	return (ERROR_CODE);
}
