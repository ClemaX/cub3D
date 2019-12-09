/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:32:29 by chamada     ###    #+. /#+    ###.fr     */
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
	ft_memcpy(&env->canvas.data[(env->canvas.bpp / 8) * (y * env->canvas.width) + (env->canvas.bpp / 8) * x], &color, (env->canvas.bpp / 8));
}
