/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 17:42:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 02:46:36 by chamada     ###    #+. /#+    ###.fr     */
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
	movement.x *= S_MOVEMENT;
	movement.y *= S_MOVEMENT;
	return (movement);
}

float					get_rotation(t_env *env)
{
	const int	half_w = env->canvas.w / 2;
	const int	half_h = env->canvas.h / 2;
	t_ivector	mouse;
	float		delta;

	if (env->focus == MOUSE)
	{
		mlx_mouse_get_pos(env->win, &mouse.x, &mouse.y);
		delta = (mouse.x - half_w) / (float)(MOUSE_SENS);
		mlx_mouse_move(env->win, half_w, half_h);
	}
	else
		delta = 0;
	if (env->input & ROT_LEFT && !(env->input & ROT_RIGHT))
		return (-S_ROTATION + delta);
	if (env->input & ROT_RIGHT && !(env->input & ROT_LEFT))
		return (S_ROTATION + delta);
	return (delta);
}

int						do_tick(t_env *env)
{
	t_vector	movement;
	float		rotation;

	if (env->focus == BACKGROUND)
		return (0);
	if ((rotation = get_rotation(env)))
	{
		vrotate(&env->map.player.plane, rotation);
		vrotate(&env->map.player.dir, rotation);
	}
	movement = get_movement(&env->map.player, env->input);
	move_player(&env->map, &movement);
	refresh_env(env);
	mlx_put_image_to_window(env->mlx, env->win, env->canvas.ptr, 0, 0);
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
