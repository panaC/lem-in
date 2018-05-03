/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:57:46 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/03 16:56:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <libft.h>
# include "lemin.h"
# define COM_START		"##start"
# define COM_END		"##end"

int				parser(t_env *e, t_string l);
int				parser_nb_ant(t_env *e, t_string l);
int				parser_room(t_env *e, t_string l);
int				parser_pipe(t_env *e, t_string l);

t_bool			parser_room_is_valid(t_list *lst, t_string l);
t_string		*parser_room_get(t_list *lst, t_string l);
t_bool			parser_room_set_mat(t_env *e, int i1, int i2);
t_string		parser_room_get_name(t_env *e, int id);

t_bool			parser_is_comment(t_string l);
void			*parser_cmp_name(void *elem, void *data);
void			*parser_cmp_id(void *elem, void *data);
void			*parser_cmp_loc(void *elem, void *data);

#endif
