/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 19:52:42 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 02:22:48 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TICK_H
# define TICK_H

# include <sys/time.h>

typedef struct	s_tick
{
	double	delta;
	double	start;
}				t_tick;

int				do_tick(t_env *env);
float			mouse_delta(t_env *env);

#endif
