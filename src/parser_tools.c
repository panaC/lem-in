/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:08:19 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 18:21:56 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>
#include "parser.h"
#include "filler.h"

t_bool			parser_is_comment(t_string l)
{
	if (l && *l && (l[0] == '#' ||
			(ft_strlen(l) > 1 && l[0] == '#' && l[1] != '#')))
		return (TRUE);
	return (FALSE);
}

void			*parser_cmp_name(void *elem, void *data)
{
	t_room		*room;

	room = (t_room*)elem;
	if (ft_strequ(room->name, (t_string)data))
		return (elem);
	return (NULL);
}

void			*parser_cmp_id(void *elem, void *data)
{
	t_room		*room;

	room = (t_room*)elem;
	if (room->id, (t_uint32)data)
		return (elem);
	return (NULL);
}

void			*parser_cmp_loc(void *elem, void *data)
{
	t_room		*room;

	room = (t_room*)elem;

	if (room->loc.x == ((t_point*)data)->x && room->loc.y == ((t_point*)data)->y)
		return (elem);
	return (NULL);
}
