/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:22:33 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 18:22:40 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define CARDINALS	"NSWE"
# define PLANES		"EWNS"

typedef enum		e_cardinal
{
	NORTH, SOUTH, WEST, EAST
}					t_cardinal;

typedef struct		s_vector
{
	double		x;
	double		y;
}					t_vector;

typedef struct		s_ivector
{
	int	x;
	int	y;
}					t_ivector;

t_vector			vector(double x, double y) __attribute__((always_inline));
t_vector			cardinal(t_cardinal direction);
t_ivector			ivector(int x, int y) __attribute__((always_inline));
t_ivector			vtoiv(t_vector vector) __attribute__((always_inline));

#endif
