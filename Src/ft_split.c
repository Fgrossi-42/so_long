/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:46:10 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/28 11:46:10 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

static int	ft_is_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_charset(str[i], charset) == 0)
		i++;
	return (i);
}

static int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset) == 1)
			str++;
		i = ft_wordlen(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_strdupp(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c, t_data *v)
{
	char		**dest;
	int			i;
	int			j;
	char		charset[2];

	charset[0] = c;
	charset[1] = '\0';
	i = -1;
	if (!s)
		return (0);
	v->height = ft_wordcount((char *)s, charset);
	dest = malloc((v->height + 1) * sizeof(char *));
	if (!dest || !s)
		return (0);
	while (++i < v->height)
	{
		while (ft_is_charset((char)*s, charset))
			s++;
		j = ft_wordlen((char *)s, charset);
		dest[i] = ft_strdupp((char *)s, j);
		s += j;
	}
	dest[v->height] = 0;
	return (dest);
}
