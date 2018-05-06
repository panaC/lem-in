/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:09:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:48:48 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "lemin.h"
#include "room.h"

t_bool			room_set_mat(t_env *e, int i1, int i2)
{
	e->mat_adj[i1 * e->mat_size + i2] = '1';
	e->mat_adj[i2 * e->mat_size + i1] = '1';
	return (TRUE);
}

t_string		room_get_name(t_env *e, int id)
{
	t_room		*ret;

	ret = (t_room*)ft_lstfind(e->lst_room, (void*)&id, room_cmp_id);
	if (ret)
		return (ret->name);
	return (NULL);
}
