/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 17:42:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 18:30:31 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <tick.h>
#include <unistd.h>

static inline void	start_tick(t_tick *tick)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	tick->start = now.tv_sec + now.tv_usec / 1000000.0;
}

static inline void	end_tick(t_tick *tick)
{
	static const float	limit = 1.0 / 60;
	struct timeval		now;

	if (tick->delta < limit)
	{
		usleep((limit - tick->delta) * 1000.0);
		tick->delta = limit;
	}
	else
	{
		gettimeofday(&now, NULL);
		tick->delta = ((now.tv_sec) + (now.tv_usec) / 1000000.0) - tick->start;
	}
}

void	do_tick(t_env *env)
{
	static t_tick	tick;

	start_tick(&tick);
	if (env->player.input & UP)
		move_player(env, env->player.dir, tick.delta * S_MOVEMENT);
	if (env->player.input & DOWN)
		move_player(env, env->player.dir, tick.delta * -S_MOVEMENT);
	if (env->player.input & LEFT)
		move_player(env, env->player.plane, tick.delta * -S_MOVEMENT);
	if (env->player.input & RIGHT)
		move_player(env, env->player.plane, tick.delta * S_MOVEMENT);
	if (env->player.input & ROT_LEFT && !(env->player.input & ROT_RIGHT))
	{
		vrotate(&env->player.dir, tick.delta * -S_ROTATION);
		vrotate(&env->player.plane, tick.delta * -S_ROTATION);
	}
	if (env->player.input & ROT_RIGHT && !(env->player.input & ROT_LEFT))
	{
		vrotate(&env->player.dir, tick.delta * S_ROTATION);
		vrotate(&env->player.plane, tick.delta * S_ROTATION);
	}
	refresh(env);
	mlx_put_image_to_window(env->mlx, env->win, env->canvas.ptr, 0, 0);
	end_tick(&tick);
}
