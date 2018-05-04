/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:10:23 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 23:01:28 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H
# include <libft.h>
# include "lemin.h"

/*
 * room.c
 */
t_bool		room_set_mat(t_env *e, int i1, int i2);
t_string	room_get_name(t_env *e, int id);

/*
 * room_set.c
 */
void		init_room(t_room *r, t_uint32 id, t_string s, t_e_type type);
t_room		*room_create(t_uint32 id, t_string s, t_e_type type, t_point loc);
t_room		*room_add_lst(t_list **l, t_string s, t_point loc, t_e_type type);

/*
 * room_cmp.c
 */
void			*room_cmp_name(void *elem, void *data);
void			*room_cmp_id(void *elem, void *data);
void			*room_cmp_loc(void *elem, void *data);

#endif
