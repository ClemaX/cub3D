/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:00:35 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 23:47:25 by chamada     ###    #+. /#+    ###.fr     */
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
	t_vector	rel;
	t_sprite_id	id;
	float		dist;
}				t_sprite;

t_list			*new_sprite(int x, int y, t_sprite_id id);
void    		print_sprite(void *sprite);
void			draw_sprites(t_env *env);
void			sprites_dist(t_env *env, t_list *sprites);
int 			sprite_cmp(void *a, void *b);

#endif
