/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:22:33 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 13:38:17 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define CARDINALS "NSWE"

typedef enum	e_cardinal
{
	NORTH, SOUTH, WEST, EAST
}				t_cardinal;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

t_vector		vector(double x, double y);
t_vector		cardinal(t_cardinal direction);

#endif
