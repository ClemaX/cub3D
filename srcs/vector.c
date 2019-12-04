/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 12:49:55 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 13:29:13 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <vector.h>

t_vector	vector(double x, double y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	cardinal(t_cardinal direction)
{
	if (direction == NORTH)
		return (vector(0, 1));
	else if (direction == SOUTH)
		return (vector(0, -1));
	else if (direction == EAST)
		return (vector(1, 0));
	else if (direction == WEST)
		return (vector(-1, 0));
	else
		return (vector(0, 0));
}
