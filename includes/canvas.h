/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:05:34 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 02:25:37 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <environment.h>

int     init_canvas(t_env *env);
void    draw_tex(t_env *env, int pos_x, int z, int size);

#endif
