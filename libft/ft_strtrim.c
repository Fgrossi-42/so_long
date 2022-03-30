/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-aless <md-aless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:56:39 by md-aless          #+#    #+#             */
/*   Updated: 2022/01/24 17:28:26 by md-aless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_string(char c, char const *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*x;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && is_string(s1[start], set))
		start++;
	while (end > start && is_string(s1[end - 1], set))
		end--;
	x = (char *) malloc(sizeof(*s1) * (end - start + 1));
	if (!x)
		return (NULL);
	while (start < end)
	{
		x[i] = s1[start];
		i++;
		start++;
	}
	x[i++] = '\0';
	return ((char *) x);
}
