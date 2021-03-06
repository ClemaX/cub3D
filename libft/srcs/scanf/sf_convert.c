/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sf_convert.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:47:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 02:32:53 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <libft.h>
#include <scanf/specs.h>

/*
**	Warning: The WILDCARD/STAR flag does increment the match count!
*/

static int	cvt_char(const char **src, t_spec spec, va_list ap)
{
	char	c;

	if (!**src)
		return (0);
	if (spec.type == PCNT)
		return (*(*src)++ == '%');
	if (spec.size == S_DEF)
		c = *(*src)++;
	else
		return (0);
	if (!(spec.flags & STAR))
		*(va_arg(ap, char*)) = c;
	return (1);
}

static int	cvt_str(const char **src, t_spec spec, va_list ap)
{
	char	*dest;
	char	*next;
	int		len;

	next = ft_strchr(*src, ' ');
	len = (next) ? next - *src : ft_strlen(*src);
	if (spec.width != -1 && spec.width < len)
		len = spec.width;
	if (!(spec.flags & STAR))
	{
		if (spec.flags & ALLOC)
		{
			if (!(dest = malloc(sizeof(*dest) * (len + 1))))
				return (0);
			*(va_arg(ap, char**)) = dest;
		}
		else
			dest = va_arg(ap, char*);
		ft_strlcpy(dest, *src, len + 1);
	}
	*src += len;
	return (1);
}

static int	cvt_num(const char **src, t_spec spec, va_list ap)
{
	int	i;

	if (spec.size == S_DEF && (ft_isdigit(**src) || ft_issign(**src)))
	{
		i = ft_atoi(*src);
		*src += ft_numlen((i < 0) ? -i : i, 10);
	}
	else
		return (0);
	*(va_arg(ap, int*)) = i;
	return (1);
}

/*
**	Format each variable according to specification
**	Note: Types are dispatched in following order: cs%pdiuxXon
*/

int			(*g_convert[11])(const char**, t_spec, va_list) = {
	cvt_char,
	cvt_str,
	cvt_char,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num
};
