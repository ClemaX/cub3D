/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:56:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 03:59:34 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <ray.h>
#include <math.h>

static t_vector			ray_dir(t_env *env, unsigned x)
{
	const double	camera_x = 2 * x / (double)env->settings.width - 1;
	t_vector		dir;

	dir.x = env->player.dir.x + env->player.plane.x * camera_x;
	dir.y = env->player.dir.y + env->player.plane.y * camera_x;
	return (dir);
}

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

static t_obstacle		get_obstacle(t_env *env, t_ray *ray)
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
	obs.distance = (obs.face == WEST || obs.face == EAST)
	? (ray->pos.x - env->player.pos.x + (1 - ray->step_dir.x) / 2) / ray->dir.x
	: (ray->pos.y - env->player.pos.y + (1 - ray->step_dir.y) / 2) / ray->dir.y;
	offset = (obs.face == WEST || obs.face == EAST)
	? env->player.pos.y + obs.distance * ray->dir.y
	: env->player.pos.x + obs.distance * ray->dir.x;
	offset -= floor(offset);
	obs.offset = (int)(offset * (double)env->tex[obs.face].width);
	if (((obs.face == WEST || obs.face == EAST) && ray->dir.x > 0)
	|| ray->dir.y < 0)
		obs.offset = env->tex[obs.face].width - obs.offset - 1;
	return (obs);
}

t_obstacle			cast_ray(t_env *env, unsigned x)
{
	t_ray	ray;

	ray.pos = vtoiv(env->player.pos);
	ray.dir = ray_dir(env, x);
	ray.step_dist = vector(fabs(1 / ray.dir.x), fabs(1 / ray.dir.y));
	if (ray.dir.x < 0)
	{
		ray.step_dir.x = -1;
		ray.side_dist.x = (env->player.pos.x - ray.pos.x) * ray.step_dist.x;
	}
	else
	{
		ray.step_dir.x = 1;
		ray.side_dist.x = (ray.pos.x + 1.0 - env->player.pos.x) * ray.step_dist.x;
	}
	if (ray.dir.y < 0)
	{
		ray.step_dir.y = -1;
		ray.side_dist.y = (env->player.pos.y - ray.pos.y) * ray.step_dist.y;
	}
	else
	{
		ray.step_dir.y = 1;
		ray.side_dist.y = (ray.pos.y + 1.0 - env->player.pos.y) * ray.step_dist.y;
	}
	return (get_obstacle(env, &ray));
}
