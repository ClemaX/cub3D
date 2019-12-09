/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 23:57:32 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 00:20:44 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <errno.h>
#include <strings.h>
#include <stdlib.h>

void	error()
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}