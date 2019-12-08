/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:56:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 16:56:31 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <ray.h>
#include <environment.h>
#include <vector.h>
#include <math.h>

static t_vector		ray_dir(t_env *env, unsigned x)
{
	const double	camera_x = 2 * x / (double)env->settings.width - 1;
	t_vector		dir;

	dir.x = env->map.player.dir.x + env->map.player.plane.x * camera_x;
	dir.y = env->map.player.dir.y + env->map.player.plane.y * camera_x;
	return (dir);
}

static double		distance(t_env *env, t_ray *ray)
{
	double	dist;
	int		hit;
	int		side;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->step_dist.x;
			ray->pos.x += ray->step_dir.x;
			side = 0;
		}
		else
		{
			ray->side_dist.y += ray->step_dist.y;
			ray->pos.y += ray->step_dir.y;
			side = 1;
		}
		if (env->map.cells[ray->pos.y * env->map.size_x + ray->pos.x].type == WALL)
			hit = 1;
	}
	if (side == 0)
		dist = (ray->pos.x - env->map.player.pos.x + (1 - ray->step_dir.x) / 2) / ray->dir.x;
	else
		dist = (ray->pos.y - env->map.player.pos.y + (1 - ray->step_dir.y) / 2) / ray->dir.y;
	return (dist);
}

double				cast_ray(t_env *env, unsigned x)
{
	t_ray	ray;

	ray.pos = vtoiv(env->map.player.pos);
	ray.dir = ray_dir(env, x);
	ray.step_dist = vector(fabs(1 / ray.dir.x), fabs(1 / ray.dir.y));
	if (ray.dir.x < 0)
	{
		ray.step_dir.x = -1;
		ray.side_dist.x = (env->map.player.pos.x - ray.pos.x) * ray.step_dist.x;
	}
	else
	{
		ray.step_dir.x = 1;
		ray.side_dist.x = (ray.pos.x + 1.0 - env->map.player.pos.x) * ray.step_dist.x;
	}
	if (ray.dir.y < 0)
	{
		ray.step_dir.y = -1;
		ray.side_dist.y = (env->map.player.pos.y - ray.pos.y) * ray.step_dist.y;
	}
	else
	{
		ray.step_dir.y = 1;
		ray.side_dist.y = (ray.pos.y + 1.0 - env->map.player.pos.y) * ray.step_dist.y;
	}
	return (distance(env, &ray));
}
