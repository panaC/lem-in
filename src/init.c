/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:59:46 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 06:59:17 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

t_bool		init(t_env *e)
{
	e->verbose = FALSE;
	e->lst_room = NULL;
	e->mat_adj = NULL;
	e->room_start = NULL;
	e->room_end = NULL;
	e->str_err = NULL;
	e->tab_path_size = 0;
	e->nb_ant_start = 0;
	e->mat_size = 0;
	e->nb_ants_moving = 1;
	e->tab_path_node_size = 0;
	return (TRUE);
}
