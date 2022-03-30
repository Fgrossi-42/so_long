/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:02:17 by md-aless          #+#    #+#             */
/*   Updated: 2022/03/30 12:11:22 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenght(int a, int b)
{
	int		count;

	count = 0;
	if (a <= 0)
		++count;
	while (a && ++count)
		a /= b;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*x;
	char	*piollo;
	int		len;
	char	*num;

	len = lenght(n, 10);
	x = malloc(sizeof(char) * (len + 1));
	if (!x)
		return (NULL);
	num = "0123456789";
	x[len] = '\0';
	if (n == 0)
		x[0] = '0';
	while (n)
	{
		if (n > 0)
			x[--len] = num[n % 10];
		else
			x[--len] = num[n % 10 * -1];
		n /= 10;
	}
	piollo = x;
	free(x);
	return (piollo);
}
