/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 19:52:42 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 22:06:19 by chamada     ###    #+. /#+    ###.fr     */
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

void			do_tick(t_env *env);
void			start_tick(t_tick *tick);
void			end_tick(t_tick *tick);

#endif
