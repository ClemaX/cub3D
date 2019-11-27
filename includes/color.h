/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 06:51:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 11:16:57 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union	u_color
{
	unsigned 			c;
	struct		s_argb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	}			rgb;
}				t_color;

#endif