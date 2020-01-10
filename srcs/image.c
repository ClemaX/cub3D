/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:17:15 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 06:05:17 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <errno.h>

int				load_image(t_env *env, t_image *img, char *path)
{
	const char *ext;

	if (path && (ext = ft_strrchr(path, '.')))
	{
		if (!ft_strncmp(ext, ".png", 4))
			img->ptr = mlx_png_file_to_image(env->mlx, path, &img->w, &img->h);
		else if (!ft_strncmp(ext, ".xpm", 4))
			img->ptr = mlx_xpm_file_to_image(env->mlx, path, &img->w, &img->h);
		else
			return (0);
		if (!img->ptr)
			return (0);
		img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->ls, &img->e);
	}
	else
		return (0);
	return (1);
}

int				load_images(t_env *env)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (!load_image(env, &env->tex[i], env->settings.tex[i]))
			return (0);
		i++;
	}
	return (1);
}
