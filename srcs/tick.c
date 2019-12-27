/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 17:42:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 13:31:27 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <tick.h>
#include <unistd.h>
#include <stdlib.h>

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
		tick->delta = (now.tv_sec + now.tv_usec / 1000000.0) - tick->start;
	}
}

static inline t_vector	get_movement(t_player *player)
{
	t_vector	movement;

	movement = vector(0, 0);
	if ((player->input & (UP | DOWN)) == UP)
		movement = player->dir;
	else if ((player->input & (DOWN | UP)) == DOWN)
	{
		movement.x -= player->dir.x;
		movement.y -= player->dir.y;
	}
	if ((player->input & (LEFT | RIGHT)) == LEFT)
	{
		movement.x -= player->plane.x;
		movement.y -= player->plane.y;
	}
	else if ((player->input & (RIGHT | LEFT)) == RIGHT)
	{
		movement.x += player->plane.x;
		movement.y += player->plane.y;
	}
	return (movement);
}

void	do_tick(t_env *env)
{
	static t_tick	tick;
	t_vector		movement;

	start_tick(&tick);
	movement = get_movement(&env->player);
	movement.x *= tick.delta * S_MOVEMENT;
	movement.y *= tick.delta * S_MOVEMENT;
	move_player(env, movement);
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

int		benchmark(t_env *env)
{
	static int		i;

	if (i == 0)
		env->player.input = UP | LEFT | ROT_LEFT;
	do_tick(env);
	if (i++ == 500)
	{
		ft_printf("%lu\n", clock());
		destroy_env(env);
		exit(0);
	}
	return (1);
}