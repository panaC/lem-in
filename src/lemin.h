/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:53:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 15:11:11 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LEMIN_H
# define LEMIN_H
# define COM_START "##start"
# define COM_END "##end"

typedef enum		e_type
{
	EMPTY,
	START,
	END,
	NODE
}					t_e_type;

typedef struct		s_room
{
	t_uint32		id;
	t_string		name;
	t_uint32		id_ant;

	/*
	 * only start ou end
	 */
	t_uint32		nb_ant;
	t_e_type		type;
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
	t_string		*mat_adj;

}					t_env;


#endif
