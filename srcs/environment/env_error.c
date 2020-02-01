/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_error.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 23:57:32 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 01:18:33 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <errno.h>
#include <strings.h>
#include <stdlib.h>

void	env_error(t_env *env)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(strerror(errno), 2);
	env_destroy(env);
	exit(1);
}
