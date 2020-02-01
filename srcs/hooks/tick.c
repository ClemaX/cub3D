/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 17:42:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 01:18:33 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <tick.h>
#include <unistd.h>
#include <stdlib.h>

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

static void				do_tick(t_env *env)
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

int						loop_hook(t_env *env)
{
	const int	half_w = env->canvas.w / 2;
	const int	half_h = env->canvas.h / 2;
	t_ivector	mouse;
	float		delta;

	if (!env->focus)
		return (0);
	mlx_mouse_get_pos(env->win, &mouse.x, &mouse.y);
	mlx_mouse_move(env->win, half_w, half_h);
	delta = (mouse.x - half_w) / (float)(MOUSE_SENS);
	vrotate(&env->map.player.dir, delta);
	vrotate(&env->map.player.plane, delta);
	if (!(delta || env->input))
		return (0);
	do_tick(env);
	return (1);
}

int						benchmark(t_env *env)
{
	static int	i;

	if (i == 0)
		env->input = UP | LEFT | ROT_LEFT;
	do_tick(env);
	if (i++ == 500)
	{
		ft_printf("%lu\n", clock());
		env_destroy(env);
		exit(0);
	}
	return (1);
}
