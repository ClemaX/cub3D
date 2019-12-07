/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:56:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 18:26:18 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <environment.h>
# include <vector.h>

typedef struct	s_ray
{
	t_ivector	pos;
	t_vector	dir;
	t_vector	step_dist;
	t_ivector	step_dir;
	t_vector	side_dist;
}				t_ray;

double			cast_ray(t_env *env, unsigned x);

#endif
