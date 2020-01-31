/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 17:42:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 01:20:27 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <tick.h>
#include <unistd.h>
#include <stdlib.h>
#include <vmath.h>

static inline t_vector	get_movement(t_player *player, t_keys input)
{
	t_vector	movement;

	movement = vector(0, 0);
	if ((input & (UP | DOWN)) == UP)
		movement = player->dir;
	else if ((input & (DOWN | UP)) == DOWN)
	{
		movement.x -= player->dir.x;
		movement.y -= player->dir.y;
	}
	if ((input & (LEFT | RIGHT)) == LEFT)
	{
		movement.x -= player->plane.x;
		movement.y -= player->plane.y;
	}
	else if ((input & (RIGHT | LEFT)) == RIGHT)
	{
		movement.x += player->plane.x;
		movement.y += player->plane.y;
	}
	return (movement);
}

void					do_tick(t_env *env)
{
	t_vector		movement;

	movement = get_movement(&env->map.player, env->input);
	movement.x *= 1 * S_MOVEMENT;
	movement.y *= 1 * S_MOVEMENT;
	move_player(&env->map, &movement);
	if (env->input & ROT_LEFT && !(env->input & ROT_RIGHT))
	{
		vrotate(&env->map.player.dir, -S_ROTATION);
		vrotate(&env->map.player.plane, -S_ROTATION);
	}
	if (env->input & ROT_RIGHT && !(env->input & ROT_LEFT))
	{
		vrotate(&env->map.player.dir, S_ROTATION);
		vrotate(&env->map.player.plane, S_ROTATION);
	}
	refresh_env(env);
	mlx_put_image_to_window(env->mlx, env->win, env->canvas.ptr, 0, 0);
}

int						benchmark(t_env *env)
{
	static int		i;

	if (i == 0)
		env->input = UP | LEFT | ROT_LEFT;
	do_tick(env);
	if (i++ == 500)
	{
		ft_printf("%lu\n", clock());
		destroy_env(env);
		exit(0);
	}
	return (1);
}
