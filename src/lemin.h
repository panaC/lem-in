/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:53:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/08 13:41:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <string.h>
# include <libft.h>
# define STDIN_FILENO	0
# define NB_PATH		100

typedef enum		e_type
{
	EMPTY,
	START,
	END,
	NODE
}					t_e_type;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	int				id;
	t_string		name;
	t_uint32		id_ant;
	t_uint32		nb_ant;
	t_e_type		type;
	t_point			loc;
}					t_room;

typedef struct		s_env
{
	t_bool			verbose;
	t_list			*lst_room;
	t_room			*room_start;
	t_room			*room_end;
	t_string		mat_adj;
	size_t			mat_size;
	t_uint32		nb_ant_start;
	t_string		str_err;
	t_list			*tab_path[NB_PATH];
	size_t			tab_path_size;
	size_t			tab_path_node_size;
	t_uint32		tab_path_node[NB_PATH];
	t_uint32		nb_ants_moving;
}					t_env;

/*
** init.c
*/
t_bool				init(t_env *e);

/*
** del.c
*/
void				del_lst_node_empty(void *a, size_t b);
void				del_lst_node(void *a, size_t b);
void				del_tab_path(t_env *e);
void				del_all(t_env *e);

#endif
