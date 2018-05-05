/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:51:45 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 23:17:24 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include <libft.h>
# include "lemin.h"
# define NODE_START		e->room_start
# define NODE_END		e->room_end

/*
 * algo.c
 */
t_bool			algo_pathfinder(t_env *e);
void			bfs_recurs(t_env *e, int id, t_list **prev, t_list **actl);

/*
 * algo_tools.c
 */
t_bool			path_tab_node_id_is_used(t_env *e, int id);
t_list			*get_list_under_node(t_env *e);
t_bool			path_tab_check_size_one(t_env *e);

#endif
