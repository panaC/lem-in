/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 03:12:37 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 21:17:47 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

void		del_lst_node_empty(__attribute__ ((unused)) void *a,
		__attribute__ ((unused)) size_t b)
{
	(void)a;
	(void)b;
}

void		del_lst_node(void *a, __attribute__ ((unused)) size_t b)
{
	ft_memdel(&a);
	(void)b;
}
