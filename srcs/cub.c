/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:40:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 18:02:45 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <environment.h>
#include <get_next_line.h>
#include <libft.h>
#include <ft_sscanf.h>

int	parse_cub(t_env *env, const char *path)
{
	int		fd;
	char	*ext;
	int		ret;
	char	*line;

	ext = ft_strrchr(path, '.');
	if (!ext || ft_strncmp(ext, ".cub", 4))
		return (0);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	clear_settings(&env->settings);
	while ((ret = get_next_line(fd, &line)) > 0 && *line != '1')
		parse_settings(&env->settings, line);
	while (ret != -1 && read_map(&env->map, line))
		if ((ret = get_next_line(fd, &line)) == -1)
			return (0);
	close(fd);
	return (1);
}
