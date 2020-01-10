/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:14:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 00:49:55 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include <vector.h>

typedef unsigned	t_keys;

typedef struct		s_player
{
	float		x;
	float		y;
	t_vector	dir;
	t_vector	plane;
}					t_player;

#include <map.h>

void				move_player(t_map *map, t_vector *movement);
t_vector			camera_transform(t_player *player, t_vector vector);

#endif
