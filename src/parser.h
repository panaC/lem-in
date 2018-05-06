/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:57:46 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 07:06:35 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <libft.h>
# include "lemin.h"
# define COM_START		"##start"
# define COM_END		"##end"
# define EMPTY_CODE		-1
# define ERROR_CODE		0
# define START_CODE		1
# define ROOM_CODE		2
# define PIPE_CODE		3

/*
 * parser.c
 */
int				parser(t_env *e, t_string l);
int				parser_nb_ant(t_env *e, t_string l);
int				parser_room(t_env *e, t_string l);
int				parser_pipe(t_env *e, t_string l);

/*
 * parser_tools.c
 */
t_bool			parser_is_comment(t_string l);
t_bool			parser_is_command(t_string l);

/*
 * parser_pipe.c
 */
t_string		*parser_room_get(t_env *e, t_string l);
t_string		*parser_room_get_err(t_env *e, t_string l);
t_bool			parser_room_is_valid(t_env *e, t_string l);
int				parser_pipe_init(t_env *e);

/*
 * Parser_room.c
 */
t_bool			parser_room_loc(t_string l, t_point *loc);
t_bool			parser_room_set_list(t_env *e, t_string s, t_point loc,
		t_e_type *i);
t_bool			parser_room_line(t_env *e, t_string l, t_e_type *i,
		t_string *ss);

/*
 * parser_handle.c
 */
void			parser_get_map(t_env *e);
void			parser_algo(t_env *e);
void			parser_verbose(t_env *e);

#endif
