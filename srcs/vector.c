/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 12:49:55 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 03:09:13 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

inline t_vector		cardinal(t_cardinal direction)
{
	if (direction == NORTH)
		return ((t_vector){.x=0, .y=-1});
	else if (direction == SOUTH)
		return ((t_vector){.x=0, .y=1});
	else if (direction == EAST)
		return ((t_vector){.x=1, .y=0});
	else if (direction == WEST)
		return ((t_vector){.x=-1, .y=0});
	else
		return ((t_vector){.x=0, .y=0});
}

void				vrotate(t_vector *vector, float alpha)
{
	const float old_x = vector->x;

	vector->x = vector->x * cosf(alpha) - vector->y * sinf(alpha);
	vector->y = old_x * sinf(alpha) + vector->y * cosf(alpha);
}
