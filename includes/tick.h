/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 19:52:42 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 00:48:35 by chamada     ###    #+. /#+    ###.fr     */
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

int				loop_hook(t_env *env);

#endif
