/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:56:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 03:16:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <environment.h>

typedef struct	s_ray
{
	int			x;
	int			y;
	t_vector	dir;
	t_vector	step_dist;
	t_ivector	step_dir;
	t_vector	side_dist;
}				t_ray;

void			init_ray(t_player *player, t_ray *ray);
t_obstacle		cast_ray(t_map *map, t_image *tex, t_ray *ray);

#endif
