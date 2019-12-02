/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:10:50 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/01 21:45:53 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <color.h>

int	set_color(t_color *color, unsigned r, unsigned g, unsigned b)
{
	if (r > 255 || g > 255 || b > 255)
		return (0);
	color->rgb.set = 0;
	color->rgb.r = (unsigned char)r;
	color->rgb.g = (unsigned char)g;
	color->rgb.b = (unsigned char)b;
	return (1);
}
