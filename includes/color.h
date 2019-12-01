/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 06:51:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 11:14:07 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union	u_color
{
	unsigned int      c;
	struct	s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		char			set;
	}		rgb;
}				t_color;

void	set_color(t_color *color,
	unsigned char r, unsigned char g, unsigned char b);

#endif
