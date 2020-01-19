/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:05:34 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 01:41:57 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <environment.h>

int		init_canvas(t_env *env);
void	draw_tex(t_env *env, int pos_x, float z, int size);

#endif
