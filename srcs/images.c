/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   images.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:17:15 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 01:13:56 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <errno.h>

static inline void		put_canvas(t_env *env, int x, int y, t_color color)
{
	*(t_color*)(env->canvas.data + (y * env->canvas.ls + x * (env->canvas.bpp / 8))) = color;
}

static inline t_color	get_color(t_image *img, int x, int y)
{
	return *(t_color*)(img->data + (y * img->ls + x * (img->bpp / 8)));
}

void					draw_stripe(t_env *env, t_stripe *stripe, t_image *tex)
{
	t_color	c;

	while (stripe->draw.y < stripe->end.y)
	{
		stripe->tex.y = (((stripe->draw.y * 256 - env->canvas.h * 128 +
			stripe->size * 128) * tex->h) / stripe->size) / 256;
		if (stripe->tex.y < 0)
			stripe->tex.y = 0;
		else if (stripe->tex.y >= tex->h)
			stripe->tex.y = tex->h - 1;
		c = get_color(tex, stripe->tex.x, stripe->tex.y);
		if (c.c)
			put_canvas(env, stripe->draw.x, stripe->draw.y, c);
		stripe->draw.y++;
	}
}

static int				load_image(t_env *env, t_image *img, char *path)
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

int						load_images(t_env *env)
{
	int	i;

	i = 0;
	while (i < 5 && load_image(env, &env->tex[i], env->settings.tex[i]))
		i++;
	return (i == 5);
}
