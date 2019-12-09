/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:05:34 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:30:34 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <environment.h>

int		init_canvas(t_env *env);
void	put_canvas(t_env *env, int x, int y, unsigned int color);

#endif