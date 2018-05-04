/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:08:19 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 23:21:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include "parser.h"
#include "lemin.h"

t_bool			parser_is_comment(t_string l)
{
	if (l && *l && l[0] == '#' && l[1] && l[1] != '#')
		return (TRUE);
	return (FALSE);
}

t_bool			parser_is_command(t_string l)
{
	if (l[0] == '#' && l[1] && l[1] == '#' &&
				!ft_strequ(l, COM_START) && !ft_strequ(l, COM_END))
		return (TRUE);
	return (FALSE);
}
