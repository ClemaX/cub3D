/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:14:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 23:10:49 by chamada     ###    #+. /#+    ###.fr     */
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
	t_keys		input;
}					t_player;

#endif
