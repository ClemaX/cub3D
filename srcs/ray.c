/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:56:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 15:39:58 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <ray.h>
#include <math.h>

static t_cardinal		step_ray(t_ray *ray)
{
	t_cardinal	face;

	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->step_dist.x;
		ray->pos.x += ray->step_dir.x;
		face = (ray->dir.x < 0) ? WEST : EAST;
	}
	else
	{
		ray->side_dist.y += ray->step_dist.y;
		ray->pos.y += ray->step_dir.y;
		face = (ray->dir.y < 0) ? NORTH : SOUTH;
	}
	return (face);
}

void				init_ray(t_env *env, t_ray *ray, int x)
{
	const double	camera_x = 2 * x / (double)env->settings.width - 1;

	ray->pos = vtoiv(env->player.pos);
	ray->dir.x = env->player.dir.x + env->player.plane.x * 0.66 * camera_x;
	ray->dir.y = env->player.dir.y + env->player.plane.y * 0.66 * camera_x;
	ray->step_dist = vector(fabs(1 / ray->dir.x), fabs(1 / ray->dir.y));
	if (ray->dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (env->player.pos.x - ray->pos.x) * ray->step_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = (ray->pos.x + 1.0 - env->player.pos.x) * ray->step_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (env->player.pos.y - ray->pos.y) * ray->step_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = (ray->pos.y + 1.0 - env->player.pos.y) * ray->step_dist.y;
	}
}

t_obstacle			cast_ray(t_env *env, t_ray *ray)
{
	t_obstacle	obs;
	int			hit;
	double		offset;

	hit = 0;
	while (!hit)
	{
		obs.face = step_ray(ray);
		if (env->map.cells[ray->pos.y * env->map.size_x + ray->pos.x].type == WALL)
			hit = 1;
	}
	if (obs.face == WEST || obs.face == EAST)
	{
		obs.distance = (ray->pos.x - env->player.pos.x + (1 - ray->step_dir.x) / 2) / ray->dir.x;
		offset = env->player.pos.y + obs.distance * ray->dir.y;
	}
	else
	{
		obs.distance = (ray->pos.y - env->player.pos.y + (1 - ray->step_dir.y) / 2) / ray->dir.y;
		offset = env->player.pos.x + obs.distance * ray->dir.x;
	}
	offset -= floor(offset);
	obs.offset = (int)(offset * (double)env->tex[obs.face].width);
	if (((obs.face == WEST || obs.face == EAST) && ray->dir.x > 0)
	|| ((obs.face == NORTH || obs.face == SOUTH) && ray->dir.y < 0))
		obs.offset = env->tex[obs.face].width - obs.offset - 1;
	return (obs);
}
