/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:53:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/02 17:40:56 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <string.h>
# include <libft.h>
# define STDIN_FILENO 0
# define COM_START "##start"
# define COM_END "##end"

typedef enum		e_type
{
	EMPTY,
	START,
	END,
	NODE
}					t_e_type;

typedef struct		s_point
{
	t_uint32		x;
	t_uint32		y;
}					t_point;

typedef struct		s_room
{
	int				id;
	t_string		name;
	t_uint32		id_ant;

	/*
	 * only start ou end
	 */
	t_uint32		nb_ant;

	t_e_type		type;
	t_point			loc;
}					t_room;

typedef struct		s_env
{
	/*
	 * ROOM
	 */
	t_list			*lst_room;
	t_room			room_start;
	t_room			room_end;
	
	/*
	 * PIPE
	 */
	t_string		mat_adj;
	size_t			mat_size;

}					t_env;

int			init(t_env *e);
void		init_room(t_room *r, t_uint32 id, t_string s, t_e_type type);
t_room		room_create(t_uint32 id, t_string s, t_e_type type, t_point loc);
void		room_add_lst(t_list **l, t_string s, t_point loc);


#endif
