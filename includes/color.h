/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 06:51:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 01:01:26 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union		u_color
{
	unsigned int	c;
	struct			s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}				rgb;
}					t_color;

int					set_color(t_color *color,
	unsigned r, unsigned g, unsigned b);

#endif
