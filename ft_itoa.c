/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:44:39 by mikim             #+#    #+#             */
/*   Updated: 2017/10/10 00:56:57 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nb)
{
	int	i;

	i = 1;
	nb < 0 ? ++i : 0;
	nb < 0 ? nb *= -1 : 0;
	while (nb > 9)
	{
		++i;
		nb /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	nb = (long)n;
	len = ft_intlen(nb);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	nb < 0 ? s[0] = '-' : 0;
	nb < 0 ? nb *= -1 : 0;
	while (nb > 9)
	{
		s[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	s[--len] = nb + '0';
	return (s);
}
