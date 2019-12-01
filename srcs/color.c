/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:10:50 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 11:18:55 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <color.h>

void	set_color(t_color *color,
	unsigned char r, unsigned char g, unsigned char b)
{
	color->rgb.set = 0;
	color->rgb.r = r;
	color->rgb.g = g;
	color->rgb.b = b;
}
