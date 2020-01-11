/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vmath.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:04:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 04:19:10 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

void			vrotate(t_vector *vector, float alpha)
{
	const float old_x = vector->x;

	vector->x = vector->x * cosf(alpha) - vector->y * sinf(alpha);
	vector->y = old_x * sinf(alpha) + vector->y * cosf(alpha);
}

inline float	vdist(t_vector *a, t_vector *b)
{
	return (sqrtf(powf(b->x - a->x, 2) + powf(b->y - a->y, 2)));
}

inline float	vmag(t_vector *vector)
{
	return (sqrtf(powf(vector->x, 2) + powf(vector->y, 2)));
}
