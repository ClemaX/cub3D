/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 05:19:25 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 20:13:18 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

#include <environment.h>

typedef struct	s_image
{
	void	*ptr;
	char	*data;
	int		w;
	int		h;
	int		bpp;
	int		ls;
	int		e;
}				t_image;

#endif
