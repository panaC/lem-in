/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:32:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/02 16:07:37 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <get_next_line.h>
#include "lemin.h"
#include "parser.h"

int		main(void)
{
	t_env		e;
	t_uint8		res;
	t_string	line;

	init(&e);
	while (1)
	{
		if (get_next_line(STDIN_FILENO, &line) > 0)
		{
			res = parser(&e, line);
			ft_memdel((void**)&line);
			if (res == 0)
				break;
		}
		else
			break;
	}
	ft_memdel((void**)&line);
	ft_putstr(res == 0 ? "ERROR\n" : "OK\n");
	return (0);
}
