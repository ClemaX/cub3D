/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 12:49:55 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 02:10:41 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

inline t_vector	vector(float x, float y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

void			vrotate(t_vector *vector, float alpha)
{
	const float old_x = vector->x;

	vector->x = vector->x * cosf(alpha) - vector->y * sinf(alpha);
	vector->y = old_x * sinf(alpha) + vector->y * cosf(alpha);
}

inline t_vector		cardinal(t_cardinal direction)
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

inline t_ivector	ivector(int x, int y)
{
	t_ivector	ivector;

	ivector.x = x;
	ivector.y = y;
	return (ivector);
}

inline t_ivector	vtoiv(t_vector vector)
{
	return (ivector((int)vector.x, (int)vector.y));
}
