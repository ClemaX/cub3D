/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:56:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 03:14:22 by chamada     ###    #+. /#+    ###.fr     */
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

void				init_ray(t_player *player, t_ray *ray)
{
	ray->step_dist =
		(t_vector){.x=fabs(1 / ray->dir.x), .y=fabs(1 / ray->dir.y)};
	if (ray->dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (player->x - ray->x) * ray->step_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = (ray->x + 1.0 - player->x) * ray->step_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (player->y - ray->y) * ray->step_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = (ray->y + 1.0 - player->y) * ray->step_dist.y;
	}
}

t_obstacle			cast_ray(t_map *map, t_image *tex, t_ray *ray)
{
	t_obstacle	obs;
	float		offset;

	while (map->cells[ray->y * map->w + ray->x] != WALL)
		obs.face = step_ray(ray);
	if (obs.face == WEST || obs.face == EAST)
	{
		obs.distance = (ray->x - map->player.x + (1 - ray->step_dir.x) / 2)
			/ ray->dir.x;
		offset = map->player.y + obs.distance * ray->dir.y;
	}
	else
	{
		obs.distance = (ray->y - map->player.y + (1 - ray->step_dir.y) / 2)
			/ ray->dir.y;
		offset = map->player.x + obs.distance * ray->dir.x;
	}
	offset -= floorf(offset);
	obs.offset = (int)(offset * (float)tex[obs.face].w);
	if (((obs.face == WEST || obs.face == EAST) && ray->dir.x > 0)
	|| ((obs.face == NORTH || obs.face == SOUTH) && ray->dir.y < 0))
		obs.offset = tex[obs.face].w - obs.offset - 1;
	return (obs);
}
