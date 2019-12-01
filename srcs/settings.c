/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   settings.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 07:56:47 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 11:10:29 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>

void	clear_settings(t_settings *settings)
{
	settings->color_c.c = 0;
	settings->color_f.c = 0;
	settings->height = 0;
	settings->width = 0;
	settings->tex.ea = NULL;
	settings->tex.no = NULL;
	settings->tex.s = NULL;
	settings->tex.so = NULL;
	settings->tex.we = NULL;
}
