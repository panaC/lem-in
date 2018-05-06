/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 02:04:53 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 06:35:13 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include <libft.h>
# include "lemin.h"

t_bool		move_ants_node(t_env *e, size_t idx, t_room *from, t_room *to);
void		move_print(t_uint32 id, t_string name, t_bool st);
void		move_init(t_env *e);
void		move_while(t_env *e);
t_bool		move_tab_path_node_is_empty(t_env *e);

#endif
