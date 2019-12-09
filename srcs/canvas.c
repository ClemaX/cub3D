/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 23:46:53 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>

int		init_canvas(t_env *env)
{
	env->canvas.img = mlx_new_image(env->mlx,
		env->settings.width, env->settings.height);
	if (!env->canvas.img)
		return (0);
	env->canvas.data = mlx_get_data_addr(env->canvas.img,
		&env->canvas.bpp, &env->canvas.ls, &env->canvas.e);
	env->canvas.width = env->settings.width;
	env->canvas.height = env->settings.height;
	return (1);
}

void	put_canvas(t_env *env, int x, int y, unsigned int color)
{
	ft_memcpy(&env->canvas.data[
		(env->canvas.bpp / 8) * (y * env->canvas.width) + (env->canvas.bpp / 8) * x]
		, &color, (env->canvas.bpp / 8));
}

void	draw_column(t_env *env, int x, t_obstacle obs)
{
	int			height;
	int			start;
	int			end;
	int			y;
//	t_vector	offset;

	height = (obs.distance < 1) ? env->settings.height
	: env->settings.height / obs.distance;
	start = -height / 2 + env->settings.height/2;
	end = height / 2 + env->settings.height / 2;
	if (start < 0)
		start = 0;
	if (end >= env->settings.height)
		end = env->settings.height - 1;
	y = 0;
	while (y < env->settings.height && y <= start)
		put_canvas(env, x, y++, 0);
	while (start <= end)
	{
		put_canvas(env, x, start++, 255);
	}
	y = end + 1;
	while (y < env->settings.height)
		put_canvas(env, x, y++, 0);
//	end - start / height;
}