/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:44:39 by mikim             #+#    #+#             */
/*   Updated: 2017/10/10 00:08:00 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	nb = (long)n;
	len = ft_intlen(n);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	nb < 0 ? s[0] = '-' : 0;
	nb < 0 ? nb *= -1 : 0;
	while (n > 9)
	{
		s[--len] = (n % 10) + 48;
		n /= 10;
	}
	s[--len] = n + 48;
	return (s);
}
