/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 23:57:32 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 21:57:52 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <errno.h>
#include <strings.h>
#include <stdlib.h>

void	error(t_env *env)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(strerror(errno), 2);
	destroy_env(env);
	exit(1);
}