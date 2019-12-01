/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:20:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 08:27:16 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <environment.h>

int	mouse_hook(int button, int x, int y, void *param);
int	key_hook(int key, t_env *param);
int	destroy_hook(void *param);

#endif
