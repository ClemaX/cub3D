/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:00:35 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 05:12:21 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

#include <environment.h>

typedef enum	e_sprite_id
{
	SPRITE
}				t_sprite_id;

typedef struct	s_sprite
{
	t_vector	pos;
	t_sprite_id	id;
}				t_sprite;

void	draw_sprites(t_env *env);

#endif
