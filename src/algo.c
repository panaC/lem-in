/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 02:27:35 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 19:12:05 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"
#include "algo.h"

t_bool			algo_pathfinder(t_env *e, t_list *lst_first_lvl)
{
	t_list		*actl;
	t_list		*prev;
	t_list		*n;
	int			id;
	int			short_id;

	short_id = -1;
	actl = NULL;
	prev = NULL;
	while (ft_lstlen(lst_first_lvl))
	{
		n = lst_first_lvl;
		actl = NULL;
		while (n)
		{
			room_push_lst(&actl, e->room_start);
			id = *((int*)n->content);
			/*fct de propagation*/
			if (/*end trouvee et ft_lstlen(actual) < ft_lstlen(previous)*/)
			{
				ft_lstdel(&prev, del_lst_node_empty);
				prev = actl;
				actl = NULL;
				short_id = id;
			}
			else
			{
				ft_lstdel(&actl, del_lst_node_empty);
			}
			n = n->next;
		}
		if (short_id > -1)
		{
			/*path find*/
			short_id = -1;
			ft_lstdelfind(&lst_first_lvl, (void*)&short_id, room_cmp_id,
					del_lst_node);
			e->tab_path[tab_path_size] = prev;
			++e->tab_path_size;
			prev = NULL;
		}
		else
			/*sort de la boucle plus de chemin valide*/
			break;
	}
	if (e->tab_path_size == 0)
		return (FALSE);
	return (TRUE);
}

t_bool			algo_pathfinder(t_env *e)
{
	t_list		*previous;
	t_list		*actual;

	previous = NULL;
	actual = NULL;
	while (TRUE)
	{
		bfs_recurs(e, NODE_START, &previous, &actual);
		if (previous)
		{
			/*
			 * stockage de la liste previous dans tab_path
			 */
			e->tab_path[e->tab_path_size] = NULL;
			ft_lstcpy(previous, &(e->tab_path[tab_path_size]));
			++e->tab_path_size;
			/*
			 * free previous et actual
			 */
		}
		else
		{
			/*
			 * Aucun nouveau chemin trouve
			 * Verifier si il y a des chemins dans tab_path
			 */
			/*
			 * free previous et actual
			 */
			if (e->tab_path_size)
				return (TRUE);
			return (FALSE);
		}
	}
	return (FALSE);
}

t_bool			bfs_reccurs(t_env *e, int id, t_list **prev, t_list **actl)
{
	t_uint32	i;
	const int	pos;
	t_room		*a;

	pos = id * e->mat_size;
	i = pos;
	while (i < pos + e->mat_size)
	{
		if (e->mat_adj[i] == '1')
		{
			id = i % e->mat_size;
			if (id == NODE_END->id)
			{
				/*
				 * Le chemin a ete trouve
				 */
				ft_lstcpy(*actl, prev);
				return (TRUE);
			}
			if (!path_tab_node_id_is_used(id))
			{
				/*
				 * Si le node id n'est pas deja utiliser dans les listes
				 * de tab_path
				 */
				a = (t_room*)ft_lstfind(*actl, (void*)&id, room_cmp_id);
				if (!a)
				{
					/*
					 * Si l'id n'est pas deja dans la liste chaine
					 * pour ne pas tourner en rond bloque le retour en arriere
					 * de la recherche
					 */
					room_push_lst(actl, a);
					bfs_recurs(e, id, prev, actl);
					/*
					 * del le maillon at (id) dans la liste actual pour
					 * pouvoir repartir car celui la est OK et chaine stocker
					 * dans previous : a cette etape l'algo continue de
					 * chercher un chemin plus cours que previous
					 */
					/*
					 * supprime le dernier node pour pouvoir repartir dans
					 * une nouvelle branche
					 */
					ft_lstpull(actl);
				}
				else
				{
					continue;
				}
			}
			else
			{
				/*
				 * node incorrect tester les autres node du lvl
				 */
				continue;
			}
		}
	}
	return (FALSE);
}
