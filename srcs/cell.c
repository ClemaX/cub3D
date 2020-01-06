/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cell.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 04:25:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 05:03:18 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <sprite.h>

int parse_cell(t_env *env, char c, int x, int y)
{
	int			type;
	t_sprite	*sprite;

	if ((type = ft_strpos(CELLS, c)) != -1)
		env->map.cells[y * env->map.w + x++] = type;
	else if (type == SPRITE)
	{
		if (!(sprite = new_sprite(x, y)))
			return (0);
		ft_lstadd_back(env->sprites, sprite);
	}
	else if ((type = ft_strpos(CARDINALS, c)) != -1 && env->player.x == -1)
	{
		env->map.cells[y * env->map.w + x++] = SPACE;
		env->player.x = x + 0.5;
		env->player.y = y + 0.5;
		env->player.dir = cardinal(type);
		env->player.plane = cardinal(ft_strpos(CARDINALS, PLANES[type]));
	}
	else if (!ft_isspace(c))
		return (0);
	return (1);
}
