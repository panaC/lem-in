/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 02:27:35 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 22:22:34 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <ft_printf.h>
#include "lemin.h"
#include "parser.h"
#include "room.h"
#include "algo.h"

//t_bool			algo_pathfinder(t_env *e, t_list *lst_first_lvl)
//{
//	t_list		*actl;
//	t_list		*prev;
//	t_list		*n;
//	int			id;
//	int			short_id;
//
//	short_id = -1;
//	actl = NULL;
//	prev = NULL;
//	while (ft_lstlen(lst_first_lvl))
//	{
//		n = lst_first_lvl;
//		actl = NULL;
//		while (n)
//		{
//			room_push_lst(&actl, e->room_start);
//			id = *((int*)n->content);
//			/*fct de propagation*/
//			if (/*end trouvee et ft_lstlen(actual) < ft_lstlen(previous)*/)
//			{
//				ft_lstdel(&prev, del_lst_node_empty);
//				prev = actl;
//				actl = NULL;
//				short_id = id;
//			}
//			else
//			{
//				ft_lstdel(&actl, del_lst_node_empty);
//			}
//			n = n->next;
//		}
//		if (short_id > -1)
//		{
//			/*path find*/
//			short_id = -1;
//			ft_lstdelfind(&lst_first_lvl, (void*)&short_id, room_cmp_id,
//					del_lst_node);
//			e->tab_path[tab_path_size] = prev;
//			++e->tab_path_size;
//			prev = NULL;
//		}
//		else
//			/*sort de la boucle plus de chemin valide*/
//			break;
//	}
//	if (e->tab_path_size == 0)
//		return (FALSE);
//	return (TRUE);
//}
//


static void print(t_list *l)
{
	/*************/
	t_list *j = l;
	t_room *b = NULL;
	int		i = 0;
	while (j)
	{
		b = (t_room*)j->content;
		if (b)
			printf("%d : id %d name %s x %d y %d\n", i, b->id, b->name, b->loc.x, b->loc.y);
		j = j->next;
		i++;
	}
	/*******************/
}

t_bool			algo_pathfinder(t_env *e)
{
	t_list		*previous;
	t_list		*actual;

	previous = NULL;
	actual = NULL;
	while (TRUE)
	{
		printf("ft algo_pathfinder (ap):\n");
		room_push_lst(&actual, NODE_START);
		bfs_recurs(e, NODE_START->id, &previous, &actual);
		if (previous)
		{
			printf("ap : Previous is set\n");
			/*
			 * stockage de la liste previous dans tab_path
			 */
			e->tab_path[e->tab_path_size] = NULL;
			ft_lstcpy(previous, &(e->tab_path[e->tab_path_size]));
			++e->tab_path_size;
			printf("ap : add previous dans tab_path\n");
			/*
			 * free previous et actual
			 */
			previous = NULL;
			actual = NULL;
		}
		else
		{
			printf("ap : previous not set -> QUIT\n");
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

void			bfs_recurs(t_env *e, int id, t_list **prev, t_list **actl)
{
	t_uint32	i;
	const int	pos = id * e->mat_size;
	t_room		*a;

	i = pos;
	printf("ft bfs : pos %d\n", pos);
	while (i < pos + e->mat_size)
	{
		printf("bfs : i %d\n", i);
		/*
		 * Recherche des '1' sur la ligne id de la matrice
		 */
		if (e->mat_adj[i] == '1')
		{
			id = i % e->mat_size;
			printf("bfs : id %d\n", id);
			if (id == NODE_END->id)
			{
				/*
				 * Le chemin a ete trouve
				 */
				printf("bfs : NODE_END trouve id %d\n", id);
				if (*prev == NULL || ft_lstlen(*actl) < ft_lstlen(*prev))
				{
					printf("bfs : actl < prev -> cpy actl dans prev\n");
					if (*prev)
						ft_lstdel(prev, del_lst_node_empty);
					*prev = NULL;
					ft_lstcpy(*actl, prev);
				}
				return ;
			}
			else if (!path_tab_node_id_is_used(e, id))
			{
				/*
				 * Si le node id n'est pas deja utiliser dans les listes
				 * de tab_path
				 */
				/*
				 * Si l'id n'est pas deja dans la liste chaine
				 * pour ne pas tourner en rond bloque le retour en arriere
				 * de la recherche
				 */
				printf("bfs : !path_tab_node_id_is_used id %d\n", id);

				a = (t_room*)ft_lstfind(*actl, (void*)&id, room_cmp_id);
				if (!a)
				{
					printf("bfs : l'id pas trouve dans la liste actl id %d\n", id);
					/*
					 * ajout du node dans la liste actual pour bfs_recurs
					 */
					a = (t_room*)ft_lstfind(e->lst_room, (void*)&id, room_cmp_id);
					if (a)
					{
						printf("bfd : node -> id %d name %s x %d y %d\n", a->id, a->name, a->loc.x, a->loc.y);
						room_push_lst(actl, a);
						print(*actl);
						printf("bfs : start recurs id %d\n", id);
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
						printf("bfs : end recurs -> lstpull %d\n", id);
						ft_lstpull(actl);
					}
				}
			}
		}
		++i;
	}
}

