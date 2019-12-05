/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 15:40:18 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <environment.h>
#include <mlx.h>

void	init_canvas(t_env *env)
{
	env->canvas.img = mlx_new_image(env->mlx,
		env->settings.width, env->settings.height);
	env->canvas.data = mlx_get_data_addr(env->canvas.img,
		&env->canvas.bpp, &env->canvas.ls, &env->canvas.e);
	env->canvas.width = env->settings.width;
	env->canvas.height = env->settings.height;
}

void	put_canvas(t_env *env, int x, int y, unsigned int color)
{
	ft_memcpy(&env->canvas.data[(env->canvas.bpp / 8) * (y * env->canvas.width) + (env->canvas.bpp / 8) * x], &color, (env->canvas.bpp / 8));
}