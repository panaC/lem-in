/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 02:04:53 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 02:28:02 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include <libft.h>
# include "lemin.h"

t_bool		move_ants_node(t_env *e, size_t idx, t_room *from, t_room *to);
void		move_print(t_uint32 id, t_string name);
void		move_init(t_env *e);
void		move_while(t_env *e);
void		move_iter(t_env *e, t_list *l, t_uint32 *it, size_t i);

#endif
