/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 01:25:46 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 22:11:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <libft.h>
#include <map.h>
#include <math.h>
#include <sprite.h>

t_sprite	*new_sprite(int x, int y)
{
	t_sprite	*sprite;

	if (!(sprite = malloc(sizeof(sprite))))
		return (0);
	sprite->pos.x = x;
	sprite->pos.y = y;
	return (sprite);
}

static void	draw_sprite(t_env *env, t_sprite *sprite)
{

}

void		draw_sprites(t_env *env)
{
	sprites_dist(env, env->sprites);
	ft_lstcmpsort(&env->sprites, );
}
