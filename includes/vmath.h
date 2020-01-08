/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vmath.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:36:07 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 20:52:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VMATH_H
#define VMATH_H

# include <vector.h>

void	        vrotate(t_vector *vector, float alpha);
inline float	vdist(t_vector *a, t_vector *b);
inline float	vmag(t_vector *vector);

#endif
