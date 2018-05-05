/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:51:45 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 21:05:18 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include <libft.h>
# include "lemin.h"
# define NODE_START		e->room_start
# define NODE_END		e->room_end

t_bool			algo_pathfinder(t_env *e);
void			bfs_recurs(t_env *e, int id, t_list **prev, t_list **actl);
t_bool			path_tab_node_id_is_used(t_env *e, int id);
t_list			*get_list_under_node(t_env *e);

#endif
