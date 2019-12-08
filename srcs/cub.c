/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:40:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 23:42:29 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <environment.h>
#include <get_next_line.h>
#include <libft.h>
#include <ft_sscanf.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	parse_cub(t_env *env, const char *path)
{
	int		fd;
	char	*ext;
	int		ret;
	char	*line;

	if (!(ext = ft_strrchr(path, '.')) || ft_strncmp(ext, ".cub", 4))
	{
		errno = EINVAL;
		return (0);
	}
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	clear_settings(&env->settings);
	while ((ret = get_next_line(fd, &line)) > 0 && *line != '1')
		if (!(parse_settings(&env->settings, line)))
			return (0);
	while (ret != -1 && read_map(&env->map, line))
		if ((ret = get_next_line(fd, &line)) == -1)
			return (0);
	close(fd);
	return (1);
}
