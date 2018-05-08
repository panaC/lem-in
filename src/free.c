/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 03:12:37 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/08 13:43:04 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

void		del_lst_node_empty(void *a, size_t b)
{
	(void)a;
	(void)b;
}

void		del_lst_node(void *a, size_t b)
{
	ft_memdel(&a);
	(void)b;
}

void		del_tab_path(t_env *e)
{
	size_t	i;

	i = 0;
	while (i < e->tab_path_size)
	{
		ft_lstdel(&(e->tab_path[i]), del_lst_node_empty);
		++i;
	}
}

void		del_all(t_env *e)
{
	t_list	*l;

	l = e->lst_room;
	while (l)
	{
		ft_strdel(&(((t_room*)l->content)->name));
		l = l->next;
	}
	ft_lstdel(&(e->lst_room), del_lst_node);
	del_tab_path(e);
	ft_memdel((void**)&(e->mat_adj));
	ft_strdel(&(e->str_err));
}
