/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 12:49:55 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 16:27:11 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

t_vector	vector(double x, double y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

/* void		vadd(t_vector a, t_vector b)
{
	t_vector	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

void		vscale(t_vector *vector, double factor)
{
	vector->x *= factor;
	vector->y *= factor;
}

void		rotate(t_vector *vector, double alpha)
{
	const t_vector	old = *vector;
	vector->x = old.x * cos(alpha) - old.y * sin(alpha);
	vector->y = -old.x * sin(alpha) + old.y * cos(alpha); 
}
*/

t_vector	cardinal(t_cardinal direction)
{
	if (direction == NORTH)
		return (vector(0, -1));
	else if (direction == SOUTH)
		return (vector(0, 1));
	else if (direction == EAST)
		return (vector(1, 0));
	else if (direction == WEST)
		return (vector(-1, 0));
	else
		return (vector(0, 0));
}
