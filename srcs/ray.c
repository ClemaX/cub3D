/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:56:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 00:53:34 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <ray.h>
#include <math.h>

static t_cardinal	step_ray(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->step_dist.x;
		ray->x += ray->step_dir.x;
		return ((ray->dir.x < 0) ? WEST : EAST);
	}
	else
	{
		ray->side_dist.y += ray->step_dist.y;
		ray->y += ray->step_dir.y;
		return ((ray->dir.y < 0) ? NORTH : SOUTH);
	}
}

void				init_ray(t_env *env, t_ray *ray, int x)
{
	const float	camera_x = 2 * x / (float)env->settings.w - 1;

	ray->x = (int) env->player.x;
	ray->y = (int) env->player.y;
	ray->dir.x = env->player.dir.x + env->player.plane.x * 0.66 * camera_x;
	ray->dir.y = env->player.dir.y + env->player.plane.y * 0.66 * camera_x;
	ray->step_dist = vector(fabs(1 / ray->dir.x), fabs(1 / ray->dir.y));
	if (ray->dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (env->player.x - ray->x) * ray->step_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = (ray->x + 1.0 - env->player.x) * ray->step_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (env->player.y - ray->y) * ray->step_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = (ray->y + 1.0 - env->player.y) * ray->step_dist.y;
	}
}

t_obstacle			cast_ray(t_env *env, t_ray *ray)
{
	t_obstacle	obs;
	float		offset;

	while (env->map.cells[ray->y * env->map.w + ray->x] != WALL)
		obs.face = step_ray(ray);
	if (obs.face == WEST || obs.face == EAST)
	{
		obs.distance = (ray->x - env->player.x + (1 - ray->step_dir.x) / 2) / ray->dir.x;
		offset = env->player.y + obs.distance * ray->dir.y;
	}
	else
	{
		obs.distance = (ray->y - env->player.y + (1 - ray->step_dir.y) / 2) / ray->dir.y;
		offset = env->player.x + obs.distance * ray->dir.x;
	}
	offset -= floorf(offset);
	obs.offset = (int)(offset * (float)env->tex[obs.face].w);
	if (((obs.face == WEST || obs.face == EAST) && ray->dir.x > 0)
	|| ((obs.face == NORTH || obs.face == SOUTH) && ray->dir.y < 0))
		obs.offset = env->tex[obs.face].w - obs.offset - 1;
	return (obs);
}
