/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:32:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/06 07:12:39 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"
#include "parser.h"
#define VERBOSE_ARG		"-v"

int		main(int argc, char **argv)
{
	t_env		e;

	init(&e);
	if (argc == 2 && ft_strequ(argv[1], VERBOSE_ARG))
		e.verbose = TRUE;
	parser_get_map(&e);
	parser_algo(&e);
	del_all(&e);
	return (0);
}
