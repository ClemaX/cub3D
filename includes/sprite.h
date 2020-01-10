/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:00:35 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 06:34:52 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

#include <environment.h>

typedef enum	e_sprite_id
{
	S_0
}				t_sprite_id;

typedef struct	s_sprite
{
	t_vector	pos;
	t_vector	rel;
	t_sprite_id	id;
	float		dist;
}				t_sprite;

t_list			*new_sprite(int x, int y, t_sprite_id id);
void			draw_sprites(t_env *env);
void			sprites_dist(t_player *player, t_list *sprites);
int 			sprite_cmp(void *a, void *b);

#endif
