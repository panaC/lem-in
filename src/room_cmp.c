/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:55:28 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 08:50:28 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"
#include "room.h"

void			*room_cmp_name(void *elem, void *data)
{
	t_room		*room;

	room = (t_room*)elem;
	if (ft_strequ(room->name, (t_string)data))
		return (elem);
	return (NULL);
}

void			*room_cmp_id(void *elem, void *data)
{
	t_room		*room;

	room = (t_room*)elem;
	if (room->id == *(int*)data)
		return (elem);
	return (NULL);
}

void			*room_cmp_loc(void *elem, void *data)
{
	t_room		*room;

	room = (t_room*)elem;
	if (room->loc.x == ((t_point*)data)->x &&
			room->loc.y == ((t_point*)data)->y)
		return (elem);
	return (NULL);
}
