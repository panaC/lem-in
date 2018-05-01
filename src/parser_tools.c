/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:08:19 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 15:10:54 by pleroux          ###   ########.fr       */
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
