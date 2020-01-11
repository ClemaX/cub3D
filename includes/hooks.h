/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 04:39:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 04:47:08 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <environment.h>

int	mouse_hook(int button, int x, int y, t_env *param);
int	key_enable(int key, t_env *env);
int	key_disable(int key, t_env *env);
int	loop_hook(t_env *env);
int	destroy_hook(t_env *param);

#endif
