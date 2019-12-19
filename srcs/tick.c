/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tick.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 17:42:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 16:20:29 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tick.h>
#include <unistd.h>

void	start_tick(t_tick *tick)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	tick->start = (now.tv_sec) + (now.tv_usec) / 1000000.0;
}

void	end_tick(t_tick *tick)
{
	static const float	limit = 1.0 / 60.0;
	struct timeval		now;

	if (tick->delta < limit)
	{
		usleep((limit - tick->delta) * 1000.0);
		tick->delta = limit;
	}
	else
	{
		gettimeofday(&now, NULL);
		tick->delta = ((now.tv_sec) + (now.tv_usec) / 1000000.0) - tick->start;
	}
}
